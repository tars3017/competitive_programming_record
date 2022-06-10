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

int arr[105];
ll dp[1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    // for (int i = 0; i <= n; ++i) {
    //     dp[i][0] = 1;
    // }
    for (int j = 0; j <= x; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (j-arr[i] >= 0) dp[j] += dp[j-arr[i]];
            dp[j] %= 1000000007;
        }
    }
    cout << dp[x] << endl;
    return 0;
}

