#include <iostream>
#include <set>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n; cin >> n;
    long long tpe, x;
    set<long long> s;
    for (int i = 0; i < n; ++i) {
        cin >> tpe >> x;
        if (tpe == 1) {
            if (s.count(x)) s.erase(x);
            else s.insert(x);
            // cout << "insert " << x << endl;
        }
        else {
            set<long long>::iterator l_ptr, r_ptr;
            if (s.size() <= 1 || x < *s.begin() || x >= *(s.rbegin())) {
                cout << -1 << endl;
                continue;
            }
            l_ptr = s.lower_bound(x);
            r_ptr = s.lower_bound(x+1);
            if (*l_ptr > x) l_ptr--;
            cout << *r_ptr - *l_ptr << endl;
        }
    }
    // [, ) not same as the problem statement!!! angry
    return 0;
}