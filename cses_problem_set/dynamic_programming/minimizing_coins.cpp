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

int arr[105];
int dp[105][1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // memset(dp[1], 0x3f, sizeof(dp[1]));
    // dp[1][arr[1]] = 1;
    memset(dp[0], 0x3f, sizeof(dp[0]));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= x; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j-arr[i] >= 0) {
                dp[i][j] = min(dp[i][j], min(dp[i][j-arr[i]], dp[i-1][j-arr[i]])+1);
                // dp[i][j] = dp[i][j-arr[i]] | dp[i-1][j] | dp[i-1][j-arr[i]];
            }
            debug(i, j, arr[i], dp[i][j]);
        }
    }
    if (dp[n][x] >= 0x3f3f3f3f) cout << -1 << endl;
    else cout << dp[n][x] << endl;
    return 0;
}

