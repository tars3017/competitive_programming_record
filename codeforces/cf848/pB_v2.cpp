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

int idx[100005];
int p[100005];
pair<ll, int> dp[100005][2];
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, d; cin >> n >> m >> d;
        memset(idx, 0, sizeof(idx));
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; ++i) {
            int num; cin >> num;
            idx[num] = i;
            dp[i][0] = {0, 0};
            dp[i][1] = {0, 0};
        }
        for (int i = 1; i <= m; ++i) {
            cin >> p[i];
        }
        dp[1][0] = {0, p[1]};
        dp[1][1] = {0, p[1]};
        // 1 -> swap  i & i-1
        
        int zero_or_one = 0;;
        int last;
        for (int i = 2; i <= m; ++i) {
            if (i == 2) {
                zero_or_one = 0;
            }
            else {
                zero_or_one = 0;
                if (dp[i-1][0].first >= INF) {
                    zero_or_one = 1;
                }
            }
            last = dp[i-1][zero_or_one].second; 

            if (idx[last] < idx[p[i]] && idx[p[i]] <= idx[last] + d) {
                dp[i][0].first = INF;
                dp[i][0].second = p[i];
                dp[i][1].first = dp[i-1][zero_or_one].first + 1;
                dp[i][1].second = p[i];
                swap(dp[i][1].second, dp[i-1][zero_or_one].second);
            }
            else {
                dp[i][0].first = dp[i-1][zero_or_one].first;
                dp[i][0].second = p[i];

                dp[i][1].first = INF;
                dp[i][1].second = p[i];
                swap(dp[i][1].second, dp[i-1][zero_or_one].second);
            }
        }
        cout << min(dp[m][0].first, dp[m][1].first) << endl;
        for (int i = 1; i <= m; ++i) {
            debug(dp[i][0].first, dp[i][0].second, dp[i][1].first, dp[i][1].second);
        }
    }
    return 0;
}

