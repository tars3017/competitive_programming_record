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

int n, m;
vector<int> g[150005];
bool vis[150005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q; cin >> q;
    while (q--) {
        memset(vis, 0, sizeof(vis));
        int x, k; cin >> x >> k;
        queue<pii> q;
        q.push({x, 0});
        int cnt = 0;
        while (!q.empty()) {
            pii now = q.front();
            q.pop();
            if (now.S > k) continue;
            if (!vis[now.F]) {
                cnt += now.F;
            }
            vis[now.F] = 1;
            debug(now.F);
            if (now.S < k) {
                for (auto nei: g[now.F]) {
                    if (!vis[nei]) {
                        /* debug(now.F); */
                        q.push({nei, now.S+1});
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    Time();
    return 0;
}

