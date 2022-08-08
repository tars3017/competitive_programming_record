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

int a1[105], a2[105];
int dp[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2;
    int Case = 1;
    while (cin >> n1 >> n2 && (n1+n2)) {
        memset(a1, 0, sizeof(a1));
        memset(a2, 0, sizeof(a2));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; ++i) {
            cin >> a1[i];
        }
        for (int i = 1; i <= n2; ++i) {
            cin >> a2[i];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (a1[i] == a2[j]) {
                    dp[i][j] = max(dp[i-1][j-1]+1, max(dp[i-1][j], dp[i][j-1]));
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        if (Case > 1) cout << endl;
        cout << "Twin Towers #" << Case++ << endl;
        cout << "Number of Tiles : " << dp[n1][n2] << endl;
    }
    Time();
    return 0;
}

