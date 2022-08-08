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

int n;
ll dp[505][200005];
int mod = 1e9 + 7;
int main() {
    // 模逆元    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll mod_inverse_of_2 = 1;
    mod_inverse_of_2 = 500000004;
    // for (int i = 1; i <= mod-2; ++i) {
    //     mod_inverse_of_2 = (mod_inverse_of_2 * 2) % mod;
    // }
    // debug(mod_inverse_of_2);
    cin >> n;
    ll sum = (1+n)*n/2;
    if (sum % 2) cout << 0 << endl;
    else {
        sum /= 2;
        // dp[0][0] = 1;
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
                if (j-i >= 0) {
                    dp[i][j] += dp[i-1][j-i];
                    dp[i][j] %= mod;
                }
            }
        }
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= sum; ++j) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        cout << (dp[n][sum]*mod_inverse_of_2)%mod << endl;
    }
    return 0;
}

