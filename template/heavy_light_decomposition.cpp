// 搭配 segment_tree.cpp 使用
int dep[100005] = {};
int mx_son[100005] = {};
int father[100005] = {};
int sz[100005] = {};
int topf[100005] = {};
int id[100005] = {};
int id_cnt;
// dep[i] 節點i的深度
// father[i] 節點i的父節點
// sz[i] 節點i的子樹大小
// mx_son[i] 節點i的重兒子編號
// topf[i] 節點i的鍊上的最低輕子節點
// id[i] 節點i的時間戳記
void dfs(int now, int fa=0) {
    dep[now] = dep[fa] + 1;
    father[now] = fa;
    sz[now] = 1;
    mx_son[now] = 0;
    for (int nxt: G[now]) {
        if (nxt != fa) {
            dfs(nxt, now);
            sz[now] += sz[nxt];
            if (sz[nxt] > sz[mx_son[now]]) {
                mx_son[now] = nxt;
            }
        }
    }
}
void dfs2(int now, int top) {
    id[now] = ++id_cnt;
    topf[now] = top;
    // 先dfs重邊
    if (mx_son[now]) dfs2(mx_son[now], top);

    for (int nxt: G[now]) {
        if (nxt != father[now] && nxt != mx_son[now]) {
            dfs2(nxt, nxt);
        }
    }
}
void edit(int x, int y, int z) {
    while (topf[x] != topf[y]) {
        if ( dep[ topf[x] ] < dep[ topf[y] ] ) swap(x, y);
        add(id[topf[x]], id[x], 1, 1, n, z);

        x = father[ topf[x] ];
    }
    if (id[x] > id[y]) swap(x, y);
    add(id[x], id[y], 1, 1, n, z);
}
int sum(int x, int y) {
    ll res = 0;
    while (topf[x] != topf[y]) {
        if (dep[ topf[x] ] < dep[ topf[y] ]) swap(x, y);
        res += query(id[topf[x]], id[x], 1, 1, n);
        res %= p;
        x = father[topf[x]];
    }
    if (id[x] > id[y]) swap(x, y);
    res += query(id[x], id[y], 1, 1, n);
    res %= p;
    return res;
}
