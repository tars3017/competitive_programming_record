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
    dep[1] = 1;
    dfs(1, 1);
    build_lca();
    cout << LCA(a, b) << endl;
}

