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
int arr[100005], dp[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    memset(dp, 0x3f, sizeof(dp));
    // for (int i = 1; i <= k+1; i++) {
    //     for (int j = 1; j < i; j++) {
    //         dp[i] = min(dp[i], abs(arr[i]-arr[j])); 
    //     }
    // }
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = max(1, i-k); j < i; j++) {
            dp[i] = min(dp[i], dp[j]+abs(arr[i]-arr[j])); 
            debug(i, j, dp[j], arr[i], arr[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}

