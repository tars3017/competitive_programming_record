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

int n, x;
int arr[1005];
int page[1005];
int dp[1005][100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> page[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-arr[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-arr[i]]+page[i]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}

