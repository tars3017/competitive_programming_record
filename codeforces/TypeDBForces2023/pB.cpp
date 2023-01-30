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


unordered_map<ll, ll> mp;
int arr[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        mp.clear();
        ll n; cin >> n;
        ll max_cnt = 1;
        for (ll i = 2; i*i <= n; ++i) {
            while (n % i == 0) {
                ++mp[i];
                n /= i;
                max_cnt = max(max_cnt, mp[i]);
            }
        }
        if (n > 1) mp[n] = 1;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            for (ll i = 0; i < (iter->second); ++i) {
                if (arr[i] == 0) arr[i] = 1;
                arr[i] *= iter->first;
            }
        }
        ll ans = 0;
        for (ll i = 0; i < max_cnt; ++i) {
            ans += arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}

