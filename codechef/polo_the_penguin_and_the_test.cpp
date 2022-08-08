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

int n, tt;
int v[105], w[105];
int dp[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> tt;
        for (int i = 1; i <= n; ++i) {
            int c, p, spend; cin >> c >> p >> spend;
            v[i] = c*p;
            w[i] = spend;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= tt; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= w[i]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
                }
            }
        }
        cout << dp[n][tt] << endl;
    }
    Time();
    return 0;
}

