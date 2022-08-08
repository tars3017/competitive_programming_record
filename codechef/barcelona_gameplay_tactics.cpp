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
const long long MOD = 1e9+7;
ll dp[1005][15], sum[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    
    while (t--) {
        int n, k; cin >> n >> k;
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        dp[0][0] = 1;
        sum[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i][j] = sum[i-1] - dp[i-1][j];
                /* if (sum[i-1] < dp[i-1][j]) while(1){} */
                dp[i][j] %= MOD;

                sum[i] += dp[i][j];
                sum[i] %= MOD;
            }
        }
        if (dp[n][0] < 0) dp[n][0] += MOD;
        cout << dp[n][0] << endl;
    }
    Time();
    return 0;
}

