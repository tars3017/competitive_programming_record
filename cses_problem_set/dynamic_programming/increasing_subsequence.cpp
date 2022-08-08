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

int n;
int arr[200005];
int dp[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    dp[1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        int pos = lower_bound(dp+1, dp+1+n, arr[i])-dp;
        debug(pos, i, arr[i]);
        if (dp[pos] != arr[i]) dp[pos] = min(dp[pos], arr[i]);
        // dp[i] = 1;
        // for (int j = 1; j < i; j++) {
        //     if (arr[i] > arr[j]) {
        //         dp[i] = max(dp[i], dp[j]+1);
        //     }
        // }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] != 0x3f3f3f3f) ans = i;
        debug(dp[i]);
    }
    cout << ans << endl;
    return 0;
}

