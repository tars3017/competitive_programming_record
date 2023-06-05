#include <iostream>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int cmd, x; cin >> cmd >> x;
        if (cmd == 1) {
            if (s.find(x) != s.end()) s.erase(x);
            else s.insert(x);
        }
        else if (cmd == 2) {
            if (s.empty() || x < *s.begin() || x >= *s.rbegin()) {
                cout << -1 << endl;
                continue;
            }
            auto l_ptr = s.lower_bound(x);
            auto r_ptr = s.lower_bound(x+1);
            if (*l_ptr > x) l_ptr--;
            cout << *r_ptr - *l_ptr << endl;
        }
    }
    return 0;
}