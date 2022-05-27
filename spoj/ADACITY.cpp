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

// use bfs to add how many people can generate the flwo char
// then use Dinic to solve it
struct Edge{
    int to, cap;
    Edge() {}
    Edge(int _to, int _cap): to(_to), cap(_cap){}
};
Edge G[505][505];
int n, m, f, t; 
vector<pii> origin[505];
int init_city[505];
void bfs(int start, int consume) {
    bool vis[505] = {};
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        vis[now] = true;
        for (auto next : origin[now]) {
            if (!vis[next.F] && consume + next.S <= t) {
                G[now][next.F].cap++;
                G[next.F][now].cap++;
                q.push(next.F);
            }
        }
    }
}
int bfs_flow(int s, int t, vector<int>& p) {
    fill(p.begin(), p.end(), -1);
    p[s] = -2;
    queue<pii> q;
    q.push({s, 0x3f3f3f3f});

    while (!q.empty()) {
        int cur = q.front().F;
        int flow = q.front().S;
        q.pop();

        for (auto next : G[cur]) {
            if (p[next.to] == -1 && next.cap) {
                p[next.to] = cur;
                int new_flow = min(flow, next.cap);
                if (next.to == t) return new_flow;
                q.push({next.to, new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> p(n+5);
    int new_flow;

    while (new_flow = bfs_flow(s, t, p)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = p[cur];
            G[prev][cur].cap -= new_flow;
            G[cur][prev].cap += new_flow;
            cur = prev;
        }
    }
    return flow;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m >> f >> t;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) 
                G[i][j] = Edge();
        }
        for (int i = 0; i <= n; i++) origin[i].clear();
        memset(init_city, 0, sizeof(init_city));
        for (int i = 0; i < f; i++) cin >> init_city[i];
        for (int i = 0; i < m; i++) {
            int a, b, l; cin >> a >> b >> l;
            origin[a].push_back({b, l});
            origin[b].push_back({a, l});
        }
        for (int i = 0; i < m; i++) {
           bfs(init_city[i], 0); 
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                ans = max(ans, maxflow(i, j));
            }
        }
        cout << ans << endl;
    }
    return 0;
}

