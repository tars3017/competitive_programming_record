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

ll dp[1000005][10];
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    memset(dp, 0, sizeof(dp));
    // reference: https://www.youtube.com/watch?v=51AkVn5Urno
    dp[1][0] = 1; // last two united
    dp[1][1] = 1; // last two no united;
    for (int i = 2; i <= 1000000; i++) {
        dp[i][0] = dp[i-1][0] * 2 + dp[i-1][1];
        dp[i][1] = dp[i-1][1] * 4 + dp[i-1][0];

        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    while (t--) {
        int n; cin >> n;
        cout << ((dp[n][0]+dp[n][1])%mod) << endl;
    }
    return 0;
}

