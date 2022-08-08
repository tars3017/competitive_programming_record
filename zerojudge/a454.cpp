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

int n;
int tt[1005], in_deg[1005], dp[1005], out_deg[1005];
vector<int> G[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(tt, 0, sizeof(t));
        memset(in_deg, 0, sizeof(in_deg));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= 1000; ++i) {
            G[i].clear();
        }
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> tt[i];
            int k; cin >> k;
            out_deg[i] = k;
            for (int j = 0; j < k; ++j) {
                int to; cin >> to;
                G[i].push_back(to);
                in_deg[to]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (in_deg[i] == 0) {
                q.push(i);
                dp[i] = 0;
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto next: G[now]) {
                dp[next] = max(dp[next], dp[now]+tt[now]);
                in_deg[next]--;
                if (in_deg[next] == 0) q.push(next);
            }
        }
        int total_time = 0;
        for (int i = 1; i <= n; ++i) {
            if (out_deg[i] == 0) {
                total_time = max(total_time, dp[i] + tt[i]);
            }
        }
        cout << total_time << endl;
    }
    Time();
    return 0;
}

