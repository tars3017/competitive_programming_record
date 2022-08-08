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

struct Node {
    int now, dis;
    Node (int _now=0, int _dis=0) {
        now = _now;
        dis = _dis;
    }
    bool operator < (const Node &rhs) const {
        return dis > rhs.dis;
    }
};
vector<pii> G[10005];
int d[100005];
bool vis[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    /* G.resize(n, vector<int>(n, 0x3f3f3f3f)); */
    memset(d, 0x3f, sizeof(d));
    /* for (int i = 0; i < n; ++i) { */
    /*     G[i].resize(n, 0x3f3f3f3f); */
    /* } */
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    d[0] = 0;
    priority_queue<Node> pq;
    pq.push(Node(0, 0));
    while(!pq.empty()) {
        Node cur = pq.top();
        vis[cur.now] = 1;
        pq.pop();
        for (auto next : G[cur.now]) {
            if (d[next.F] > next.S + d[cur.now]) {
                d[next.F] = next.S + d[cur.now];
                pq.push(Node(next.F, d[next.F]));
            }
        }
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] != 0x3f3f3f3f) {
            ans = max(ans, d[i]);
        }
        else cnt++;
    }
    cout << ans << endl << cnt << endl;
    cout << endl;
    Time();
    return 0;
}
