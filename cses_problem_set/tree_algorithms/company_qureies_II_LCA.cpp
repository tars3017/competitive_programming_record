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

vector<int> tree[200005];
int fa[25][200005] = {};
int dep[200005] = {};
int n, q; 
void dfs(int now, int par) {
    fa[0][now] = par; 
    debug(0, now, fa[0][now], par);
    for (auto nxt: tree[now]) {
        if (!dep[nxt]) {
            dep[nxt] = dep[now] + 1;
            dfs(nxt, now);
        }
    }
}
void build_lca() {
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            fa[i][j] = fa[i-1][ fa[i-1][j] ];
            assert(fa[i][j] >= 0);
        }
    }
}
int LCA(int a, int b) {
    debug(a, b);
    if (dep[a] < dep[b]) swap(a, b);

    int step = dep[a] - dep[b];
    for (int i = 0; i < 20; ++i) {
        if (step>>i & 1) {
            a = fa[i][a];
        }
    }
    debug(step, a, b, fa[0][a], fa[0][b]);
    if (a == b) return a;
    for (int i = 19; i >= 0; --i) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i <= n; ++i) tree[i].clear();
    for (int i = 2; i <= n; ++i) {
        int par; cin >> par;
        tree[par].push_back(i);
    }
    dep[1] = 1;
    dfs(1, 1);
    build_lca();
    while (q--) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
    return 0;
}

