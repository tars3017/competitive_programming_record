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
set<int> fish[1005];
// int graph[1005][1005], graph1[1005][1005], graph2[1005][1005];
int graph[1005][1005];
struct Node {
    int num, fish_get, dis;
    bool from[1005];
    Node(int _n, int _f, int _d): num(_n), fish_get(_f), dis(_d){}
    Node(int _n, int _f, int _d, int _from): num(_n), fish_get(_f), dis(_d){}
    Node(){}
};
bool vis[1005];
vector<pii> candidate;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        for (int j = 0; j < t; j++) {
            int tmp; cin >> tmp;
            fish[i].insert(tmp);
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, dis; cin >> u >> v >> dis;
        // graph[u].push_back(v);
        // graph[v].push_back(u);
        graph[u][v] = dis;
        graph[v][u] = dis;
    }
    stack<Node> q;
    int fish_get = 0;
    for (auto iter = fish[1].begin(); iter != fish[1].end(); iter++) {
        fish_get |= ( 1 << ((*iter) - 1) ) ; 
    }
    bool tmp[1005];
    tmp[1] = true;
    q.push(Node(1, fish_get, 0, tmp));
    // while(!q.empty()) {
    //     Node now = q.top(); q.pop();
    //     if (now.num == n) {
    //         candidate.push_back({now.dis, now.fish_get});
    //         continue;
    //     }
    //     for (int i = 1; i <= n; i++) {
    //         if (!vis[i] && i != now.from && graph[now.num][i]) {
    //             int mask = now.fish_get;
    //             for (auto iter = fish[i].begin(); iter != fish[i].end(); iter++) {
    //                 mask |= ( 1 << ((*iter) - 1) );
    //             }
    //             q.push(Node(i, mask, graph[now.num][i] + now.dis, now.num));
    //         }
    //     }
    // }
    // int ans = 0x3f3f3f3f;
    // for (pii i : candidate) {
    //     for (pii j : candidate) {
    //         if (i.F == j.F && i.S == j.S) continue;
    //         if ( (i.S | j.S) == ( (1<<k)-1 ) ) {
    //             ans = min(ans, max(i.F, j.F));
    //         }
    //     }
    // }
    // cout << ans << endl;
    return 0;
}

