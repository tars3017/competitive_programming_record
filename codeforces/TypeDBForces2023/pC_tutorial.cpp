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

int n, s; 
int arr[200005];
ll dp[200005][2];
ll x[200005], y[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> s;
        // memset(arr, 0, sizeof(arr));
        // memset(x, 0, sizeof(x));
        // memset(y, 0, sizeof(y));
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        x[1] = y[1] = arr[1];
        x[n] = y[n] = arr[n];
        for (int i = 2; i <= n-1; ++i) {
            if (arr[i] <= s) {
                x[i] = 0;
                y[i] = arr[i];
            }
            else {
                x[i] = s;
                y[i] = arr[i] - s;
            }
        }
        dp[1][0] = dp[1][1] = 0;
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = min(dp[i-1][0] + y[i-1]*x[i], dp[i-1][1] + x[i-1]*x[i]);
            dp[i][1] = min(dp[i-1][0] + y[i-1]*y[i], dp[i-1][1] + x[i-1]*y[i]);
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}

