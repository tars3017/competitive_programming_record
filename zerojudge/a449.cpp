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

int arr[2005];
int dp[2005][100005];
int from[2005][10005];
bool gone[2005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, m; cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sort(arr+1, arr+1+n);
    int total = 0;
    for (int l = 1; l <= k; ++l) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0; 
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = dp[i-1][j];
                if (gone[i]) {
                    dp[i][j] = dp[i-1][j];
                    break;
                }
                if (j-1 >= 0 && dp[i-1][ j-1 ] + arr[i] < dp[i][j]) {
                    dp[i][j] = dp[i-1][ j-1 ] + arr[i];
                    from[i][j] = 1;
                }
            }
        }
        int start = 0;
        for (int j = n; j >= 1; --j) {
            if (dp[n][j] <= m) {
                start = j;
                break;
            }
        }
        int cnt_now = 0;
        for (int i = n, j = start; i >= 1; --i) {
            if (from[i][j] && !gone[i]) {
                debug(i);
                gone[i] = true;
                j -= 1;
                cnt_now++;
            }
        }
        total += cnt_now;
    }
    cout << total << endl;
    Time();
    return 0;
}

