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

int arr[200005];
ll dp[200005][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        dp[2][0] = arr[1] + arr[2];
        dp[2][1] = -arr[1]-arr[2];
        for (int i = 3; i <= n; ++i) {
            dp[i][0] = arr[i] + max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = -arr[i] + max(dp[i-1][0]-arr[i-1]-arr[i-1], 
                                            dp[i-1][1]+arr[i-1]+arr[i-1]);
        }
        for (int i = 2; i <= n; ++i) {
            debug(dp[i][0], dp[i][1]);
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}

