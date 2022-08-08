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

int arr[105];
int dp[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[0][0] = 1;
    /* for (int i = 0; i <= arr[1]; ++i) dp[1][i] = 1; */
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            /* if (j-arr[i] < 0) continue; */
            debug(i, j, j-arr[i], j);
            for (int k = max(j-arr[i], 0); k <= j; ++k) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 1000007;
            }
        }
    }
    for (int i = 0; i <= arr[1]; ++i) {
        debug(dp[1][i]);
    }
    cout << dp[n][m] << endl;
    Time();
    return 0;
}
