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
#else 
#define debug(...)
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long

ll arr[200005];
ll sum_of_digits(ll x) {
    ll res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
set<ll> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        s.clear();
        memset(arr, 0, sizeof(arr));
        int n, q; cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            s.insert(i);
        }
        int opt;
        while (q--) {
            cin >> opt;
            if (opt == 1) {
                int l, r; cin >> l >> r;
                while (!s.empty()) {
                    set<ll>::iterator iter = s.lower_bound(l);
                    if (iter == s.end() || *iter > r) break;

                    arr[*iter] = sum_of_digits(arr[*iter]);
                    l = (*iter) + 1;
                    if (arr[*iter] < 10) s.erase(iter);
                }
            }
            else if (opt == 2) {
                int x; cin >> x;
                cout << arr[x] << endl;
            }
        }
    }
    return 0;
}

