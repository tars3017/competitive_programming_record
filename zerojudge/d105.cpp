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

int dp[35][35];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    dp[1][2] = 1, dp[1][n] = 1;
    // pass num | people num
    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            debug(i, j);
            if (j == 1) {
                if ( n == 2) 
                    dp[i][j] = dp[i-1][2];
                else 
                    dp[i][j] = dp[i-1][2] + dp[i-1][n];
            }
            else if (j == n) {
                if (n-1 == 1) 
                    dp[i][j] = dp[i-1][1];
                else 
                    dp[i][j] = dp[i-1][1] + dp[i-1][n-1];
            }
            else {
                if (j-1 == j+1) 
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
            }
        }
    }
    cout << dp[m][1] << endl;
    Time();
    return 0;
}

