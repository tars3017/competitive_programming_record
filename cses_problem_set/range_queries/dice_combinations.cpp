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

int dp[1000005] = {}; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    dp[1] = 1, dp[0] = 1; 
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i-j < 0) break; 
            dp[i] += dp[i-j];
            dp[i] %= 1000000007;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

