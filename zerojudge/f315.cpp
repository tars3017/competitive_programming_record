#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do{\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T>void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#define Time() cerr << "Time elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " s.\n";
#else 
#define debug(...)
#define Time()
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long

ll dc(vector<int> arr, int low, int high) {
    if (arr.size() <= 2) {
        return 0;
    }
    vector<int> small, big;
    set<int> s;
    int mid = (low + high) / 2;
    ll ans = 0;
    for (int i : arr) {
        if (i <= mid) {
            ans += s.size(); // 被夾在幾個大數中
            small.push_back(i); 
        }
        else {
            big.push_back(i);
            if (s.count(i)) {
                s.erase(i);
            }
            else {
                s.insert(i);
            }
        }
    }
    ans += dc(small, low, mid);
    ans += dc(big, mid+1, high);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 1; i <= 2*n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }
    cout << dc(v, 1, n) << endl;
    Time();
    return 0;
}

