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

int dp[205][205];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m && (n+m)) {
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i][j-1]*i + dp[i-1][j-1];
                dp[i][j] %= 1000000;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += dp[i][m];
            ans %= 1000000;
        }
        cout << ans << endl;
    }
    Time();
    return 0;
}

