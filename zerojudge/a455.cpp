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

int box[55];
int good[1005];
ll dp[5005];
int p[1005][5005];
bool buy[1005];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> box[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> good[i];
    }
    sort(box+1, box+1+m);
    sort(good+1, good+1+n, cmp);
    /* for (int i = 1; i <= m; ++i) { */
    /*     cout << box[i] << ' '; */
    /* } */
    /* cout << endl; */
    /* for (int i = 1; i <= n; ++i) { */
    /*     cout << good[i] << ' '; */
    /* } */
    /* cout << endl; */
    int ans = 0;
    for (int k = 1; k <= m; ++k) {
        debug(box[k]);
        memset(dp, 0, sizeof(dp));
        memset(p, 0, sizeof(p));
        if (!buy[1] && good[1] <= box[k]) {

            for (int j = good[1]; j <= box[k]; ++j) {
                dp[j] = 1;
                p[1][j] = 1;
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (buy[i]) continue;
            for (int j = box[k]; j >= 0; --j) {
                if (j-good[i] >= 0 && dp[j-good[i]]+1 > dp[j]) {
                    dp[j] = dp[j-good[i]]+1;
                    p[i][j] = 1;
                }
                /* else { */
                /*     dp[j] = dp[j]; */
                /*     p[i][j] = 0; */
                /* } */
            }
        }
        if (dp[box[k]] == 0) break;
        ans += dp[box[k]];
        debug(dp[box[k]]);
        for (int i = n, j = box[k]; i > 0; --i) {
            if (p[i][j]) {
                buy[i] = 1;
                debug("mark", i);
                j -= good[i];
            }
        }
    }
    cout << ans << endl;
    Time();
    return 0;
}

