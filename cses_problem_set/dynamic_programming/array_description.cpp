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

int arr[100005];
ll dp[100005][105];
int mod = 1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    if (arr[1]) dp[1][arr[1]] = 1;
    else {
        for (int j = 1; j <= m; j++) dp[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i]) {
            dp[i][arr[i]] = dp[i-1][arr[i]-1] + dp[i-1][arr[i]] + dp[i-1][arr[i]+1];
            dp[i][arr[i]] %= mod;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i-1][j];
            if (j-1 >= 1) {
                dp[i][j] += dp[i-1][j-1];
            }
            if (j+1 <= m) {
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= mod;
        }
    }
    ll ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= m; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

