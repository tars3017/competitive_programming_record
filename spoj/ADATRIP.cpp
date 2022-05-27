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
struct edge {
    ll to, w;
    edge(ll _to=0, ll _w=0) {
        to = _to, w = _w;
    }
};
ll n, m, q;
vector<edge> g[500005];
ll d[500005];
bool vis[500005];
void dijkstra(ll s) {
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});    
    while (!pq.empty()) {
        // int nxt = -1, value = 0x3f3f3f3f;
        // for (int i = 0; i < n; i++) {
        //     if (!vis[i] && d[i] < value) {
        //         nxt = i;
        //         value = d[i];
        //     }
        // }
        // if (nxt == -1) break;
        pii nxt = pq.top();
        pq.pop();
        if (vis[nxt.S]) continue;
        debug(nxt.S);
        vis[nxt.S] = true;
        for (auto eg : g[nxt.S]) {
            if (d[eg.to] > d[nxt.S] + eg.w) {
                d[eg.to] = d[nxt.S] + eg.w;
                if (!vis[eg.to]) pq.push({d[eg.to], eg.to});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        ll a, b, l; cin >> a >> b >> l;
        g[a].push_back(edge(b, l));
        g[b].push_back(edge(a, l));
    }

    // dijkstra
    while (q--) {
        ll start; cin >> start;
        dijkstra(start);
        // for (int i = 0; i < n; i++) {
        //     cout << d[i] << ' ' ;
        // }
        // cout << endl;
        ll ans_v = 0;
        for (int i = 1; i < n; i++) {
            if (d[i] < 0x3f3f3f3f3f3f3f3f && d[i] > ans_v) {
                ans_v = d[i];
            }
        }
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == ans_v) cnt++;
        }
        debug(ans_v);
        cout << ans_v << ' ' << cnt << endl;
    }
    return 0;
}

