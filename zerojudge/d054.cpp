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

ll dp[45];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    dp[0] = 1;
    dp[1] = 1, dp[2] = 5;
    for (int i = 3; i <= 40; ++i) {
        dp[i] = dp[i-1] + dp[i-2]*4 + dp[i-3]*2;
    }
    while (t--) {
        int n; cin >> n;
        cout << dp[n] << endl; 
    }
    Time();
    return 0;
}

