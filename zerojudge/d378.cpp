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

int arr[110][110];
int dp[110][110];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; 
    int Case = 1;
    while (cin >> n >> m) {
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> arr[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) dp[i][0] = 0x3f3f3f3f;
        for (int j = 1; j <= m; ++j) dp[0][j] = 0x3f3f3f3f;
        dp[0][0] = 0;
        dp[1][1] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) continue;
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
            }
        }
        cout << "Case #" << Case++ << " :\n";
        cout << dp[n][m] << endl;
    }
    Time();
    return 0;
}

