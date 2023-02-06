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

        // if (idx[p[1]] < idx[p[2]] && idx[p[2]] <= idx[p[1]] + d) {
        //     dp[2][0] = INF;
        //     dp[2][1] = 1;
        // }
        // else {
        //     dp[2][0] = 0;
        //     swap(p[1], p[2]);
        //     if (idx[p[1]] < idx[p[2]] && idx[p[2]] <= idx[p[1]] + d) {
        //         dp[2][1] = INF;
        //     }
        //     else {
        //         dp[2][1] = 0;
        //     }
        //     swap(p[1], p[2]);
        // }
        for (int i = 2; i <= m; ++i) {
            debug(p[i], dp[i-1][0].first, dp[i-1][0].second, dp[i-1][1].first, dp[i-1][1].second);
            int last = dp[i-1][0].second;
            dp[i][0].second = p[i];
            dp[i][1].second = p[i];
            if (idx[last] < idx[p[i]] && idx[p[i]] <= idx[last] + d) {
                dp[i][1].first = dp[i-1][0].first + 1;
                swap(dp[i][1].second, dp[i-1][0].second);

                dp[i][0].first = INF;
            }
            else {
                swap(last, p[i]);
                dp[i][0].first = dp[i-1][0].first;
                if (idx[last] < idx[p[i]] && idx[p[i]] <= idx[last] + d) {
                    // unable to swap
                    dp[i][1].first = INF;
                }
                else {
                    dp[i][1].first = dp[i-1][0].first;
                }
                swap(last, p[i]);
            }

            last = dp[i-1][1].second;
            if (idx[last] < idx[p[i]] && idx[p[i]] <= idx[last] + d) {
                if (dp[i-1][1].first + 1 < dp[i][1].first) {
                    dp[i][1].first = dp[i-1][1].first + 1;
                    swap(dp[i][1].second, dp[i-1][1].second);
                }
                else if (dp[i-1][0].first + 1 == dp[i][1].first) assert(0);

                dp[i][0].first = INF;
            }
            else {
                swap(last, p[i]);
                dp[i][0].first = dp[i-1][1].first;
                if (idx[last] < idx[p[i]] && idx[p[i]] <= idx[last] + d) {
                    // unable to swap
                    dp[i][1].first = INF;
                }
                else {
                    if (dp[i-1][1].first < dp[i][1].first) {
                        dp[i][1].first = dp[i-1][1].first;
                        swap(dp[i][1].second, dp[i-1][1].second);
                    }
                }
                swap(last, p[i]);
            }
        }
        cout << min(dp[m][0].first, dp[m][1].first) << endl;
    }
    return 0;
}

