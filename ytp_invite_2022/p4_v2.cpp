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

const int MAXN = 1e8;
ll arr[2005];
ll dp[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int d, y; cin >> d >> y;
    ll total = 0;
    for (int i = 1; i <= d; ++i) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int j = 1; j <= y; ++j) {
        for (int i = 1; i <= d; ++i) {
            if (j-arr[i] >= 0) {
                debug(j, dp[j], j-arr[i], dp[j-arr[i]]);
                dp[j] += dp[j-arr[i]];
            }
        }
    }
    for (int i = 0; i <= y; ++i) {
        cout << dp[i] << ' ';
    }
    cout << endl;
    cout << dp[y] << endl;
    Time();
    return 0;
}

