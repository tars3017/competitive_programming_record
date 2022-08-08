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

unsigned long long dp[55][5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    // 0 --> up 1 --> left 2 --> right
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1];
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2] << endl;
    Time();
    return 0;
}

