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

pii w[205], v[205];
pii dp[205][1005];
bool cmp(pii a, pii b) {
    if (a.F != b.F) 
        return a.F > b.F;
    return a.S > b.S;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, l; cin >> n >> t >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i].F >> w[i].S;
    }
    sort(w+1, w+1+n, cmp);
    for (int j = 0; j < w[1].F; ++j) {
        /* dp[1][j].F = -0x3f3f3f3f; */
    }
    int ans = 0;
    for (int j = w[1].F; j <= t; ++j) {
        dp[1][j].F = w[1].S;
        dp[1][j].S = 1;
        ans = max(ans, dp[1][j].F);
    }
    for (int i = 2; i <= n; ++i) {
            for (int k = 1; k <= l; ++k) {
        for (int j = 0; j <= t; ++j) {
            dp[i][j].F = dp[i-1][j].F;
            dp[i][j].S = dp[i-1][j].S;
                if (j-w[i].F*k >= 0) {
                    debug(i, j, k, j-w[i].F*k, dp[i-1][j-w[i].F*k].F, dp[i-1][j-w[i].F*k].S);
                }
                if (j - w[i].F*k >= 0 && dp[i-1][j-w[i].F*k].S+1 == k) {
                    debug("match", i, j, k, dp[i-1][j-w[i].F*k].F, dp[i-1][j-w[i].F*k].S);
                    if (dp[i-1][j-w[i].F*k].F+w[i].S > dp[i][j].F) {
                        dp[i][j].F = dp[i-1][j-w[i].F*k].F + w[i].S;
                        dp[i][j].S = dp[i-1][j-w[i].F*k].S + 1;
                        debug("bigger", dp[i][j].F);
                        ans = max(ans, dp[i][j].F);
                    }
                    /* debug(dp[i][j].F, dp[i][j].S); */
                }
            }
        }
    }
    cout << ans << endl;
    Time();
    return 0;
}

