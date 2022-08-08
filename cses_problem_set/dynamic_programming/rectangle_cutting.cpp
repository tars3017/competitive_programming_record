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

int dp[505][505];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b; cin >> a >> b;
    dp[1][2] = dp[2][1] = 1;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) continue;
            dp[i][j] = 0x3f3f3f3f;
            debug(i, j);
            for (int k = 1; k < i; ++k) {
                debug(k, j, a-k, j);
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1); 
            }

            for (int k = 1; k < j; ++k) {
                debug(i, k, i, b-k);
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1); 
            }
        }
    }
    // for (int i = 1; i <= a; ++i) {
    //     for (int j = 1; j <= b; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[a][b] << endl;
    return 0;
}

