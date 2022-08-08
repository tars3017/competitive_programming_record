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

ll dp[105][5][2];
const int mod = 1e9 + 9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n;
        memset(dp, 0, sizeof(dp));
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        /* else if (n == 2) { */
        /*     cout << 4 << endl; */
        /*     continue; */
        /* } */
        dp[2][0][1] = 1;
        dp[2][1][1] = 1;
        dp[2][2][0] = 1;
        dp[2][2][1] = 1;
        dp[2][3][1] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i][0][1] = dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1] + dp[i-1][3][1];
            dp[i][1][1] = dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1] + dp[i-1][3][1];
            dp[i][2][0] = dp[i-1][2][0];
            dp[i][2][1] = dp[i-1][0][1] + dp[i-1][1][1] + dp[i-1][2][1] + dp[i-1][3][1];
            dp[i][3][1] = dp[i-1][2][0];
            for (int j = 0; j < 4; ++j) {
                dp[i][j][0] %= mod;
                dp[i][j][1] %= mod;
            }
        }
        ll ans = 0;
        for (int j = 0; j < 4; ++j) {
            ans += dp[n][j][1];
            ans %= mod;
        }
        ans %= mod;
        cout << ans << endl;
    }
    Time();
    return 0;
}

