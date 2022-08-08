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
ll x;
int arr[25];
pair<ll, ll> dp[(1<<22)];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    dp[1<<0] = {1, x-arr[0]};
    for (int j = 2; j < (1<<n); ++j) {
        dp[j].F = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            if (j & (1<<i)) {
                int mask = j ^ (1<<i);
                if (dp[mask].S - arr[i] < 0 && dp[mask].F+1 <= dp[j].F) {
                    debug("a");
                    dp[j].F = dp[mask].F + 1;
                    dp[j].S = max(x - arr[i], dp[mask].S);
                }
                else if (dp[mask].S - arr[i] >= 0 && dp[mask].F <= dp[j].F) {
                    debug("b");
                    dp[j].F = dp[mask].F; 
                    dp[j].S = dp[mask].S - arr[i];
                }
                else {
                    debug("here");
                }
                debug(i, j, i-1, mask, dp[mask].F, dp[mask].S, dp[j].F, dp[j].S);
            } 
        }
    }
    cout << dp[(1<<n) - 1].F << endl;
    return 0;
}

