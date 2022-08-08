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

int arr[105];
ll dp[105][105];
ll solve(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    ll now_max = 0;
    for (int i = l; i < r; ++i) {
        if ( (r-l+1) % 2 ) {
            now_max = max(now_max, solve(l, i) * solve(i+1, r));
        }
        else {
            now_max = max(now_max, solve(l, i) + solve(i+1, r));
        }
    }
    dp[l][r] = now_max;
    return dp[l][r];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][i] = arr[i];
        }
        cout << solve(1, n) << endl; 
    }
    Time();
    return 0;
}

