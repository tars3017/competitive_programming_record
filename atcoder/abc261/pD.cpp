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

ll x[5005];
int bonus[5005];
ll dp[5005][5005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; ++i) {
        int c, y; cin >> c >> y;
        bonus[c] += y;
        /* bonus[c] = y; */
        /* bonus[c] += x[c]; */
        /* debug("plus", c, x[c], bonus[c]); */
    }
    dp[1][1] = x[1]+bonus[1];
    for (int j = 2; j <= n; ++j) {
        dp[1][j] = LLONG_MIN;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            debug(i, j);
            if (j == 0) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k]);
                }
                debug("j=0", dp[i][j], x[i]);
            }
            else {
                dp[i][j] = dp[i-1][j-1] + x[i] + bonus[j];
                debug(dp[i][j], dp[i-1][j-1], x[i], bonus[j]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    Time();
    return 0;
}

