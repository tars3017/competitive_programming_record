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
#define MAXN 1005
#define MAXMASK 2000
int a[MAXN];
vector<pii> adj[MAXN];
int dist[MAXN][MAXMASK];
set<pair<int, pii>> S;
void push(int vn, int vm, int vv) {
    if (dist[vn][vm] <= vv) {
        return ;
    }
    pair<int, pii> mp = make_pair(dist[vn][vm], make_pair(vn, vm));
    if (S.find(mp) != S.end()) S.erase(S.find(mp));
    dist[vn][vm] = vv;
    mp.first = vv;
    S.insert(mp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        for (int j = 0; j < t; j++) {
            int tmp; cin >> tmp;
            a[i] |= (1<< (tmp-1));
        }
    }
    set<pii> edges;
    for (int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        edges.insert( make_pair(min(x, y), max(x, y)) );
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    memset(dist, 0x3f, sizeof(dist));
    // for (int i = 0; i < MAXN; i++) {
    //     for (int j = 0; j < MAXMASK; j++) cout << dist[i][j] << ' ';
    //     cout << endl;
    // }
    push(1, a[1], 0);
    while (!S.empty()) {
        int vn = S.begin()->second.first;
        int vm = S.begin()->second.second;
        S.erase(S.begin());
        for (int i = 0; i < adj[vn].size(); i++) {
            push(adj[vn][i].first, vm | a[adj[vn][i].first], dist[vn][vm]+adj[vn][i].second);
        }
    }
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < (1<<k); i++) {
        for (int j = i; j < (1<<k); j++) {
            if ((i | j) == ((1<<k) - 1)) ret = min(ret, max(dist[n][i], dist[n][j]));
        }
    }
    cout << ret << endl; 
    return 0;
}

