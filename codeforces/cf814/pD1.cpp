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

int arr[5005];
int dp[5005][1<<13];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // Thanks angelo_torres
    int t; cin >> t;
    while (t--) {
        /* memset(arr, 0, sizeof(arr)); */
        /* memset(dp, 0, sizeof(dp)); */
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        // dp[i][v] spend time to clear first i number with nth number is v
        dp[1][0] = 0;
        for (int j = 1; j < 8192; ++j) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 8192; ++j) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][arr[i-1]];
                    continue;
                }
                dp[i][j] = n+5;
                dp[i][j] = min(dp[i][j], dp[i-1][arr[i-1]^j]+1);
                dp[i][j] = min(dp[i][j], dp[i-1][arr[i-1]]+1);
            }
        }
        cout << dp[n][arr[n]] << endl;
    }
    Time();
    return 0;
}

