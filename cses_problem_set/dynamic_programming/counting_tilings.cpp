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

int n, m;
ll dp[15][1005][5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    // 0 | 1 | 2 | 3 -> u | < | ^ | >
    dp[0][0][1] = dp[0][0][2] = 1;
    for (int j = 1; j < m; ++j) {
        dp[0][j][3] = dp[0][j-1][1];
        dp[0][j][1] = dp[0][j-1][3] + dp[0][j-1][2];
        dp[0][j][2] = dp[0][j-1][3] + dp[0][j-1][2];
    }
    for (int i = 1; i < n; ++i) {
        dp[i][0][1] = dp[i][0][2] = 1;
        dp[i][0][0] = dp[i-1][0][2];
        for (int j = 1; j < m; ++j) {
            dp[i][j][0] = dp[i-1][j][2];
            dp[i][j][1] = (dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][3]) * (dp[i][j-1][0]+dp[i][j-1][3]+dp[i][j-1][2]);
            dp[i][j][2] = dp[i][j][1];
            dp[i][j][3] = 
        }
    }
    return 0;
}

