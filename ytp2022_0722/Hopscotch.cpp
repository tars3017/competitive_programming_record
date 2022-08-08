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

const int MAXN = 500005;
const int MOD = 1000000007;
pii arr[MAXN];
int dp[MAXN];
bool cmpt(pii a, pii b) {
    if (a.F != b.F) {
        return a.F < b.F;
    }
    return a.S < b.S;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].S;
        dp[i] = 1;
        arr[i].F = i;
    }
    sort(arr+1, arr+1+n, cmp);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (abs(arr[i]-arr[j]) <= 2) {
                dp[i] += dp[j];
                dp[i] %= MOD; 
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans << endl;
    Time();
    return 0;
}

