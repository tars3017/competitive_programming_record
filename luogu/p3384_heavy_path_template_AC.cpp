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

int n, m, r, p;
vector<int> G[100005];
int arr[100005];

struct Node {
    ll data, chg;
}ST[100005*4];
void pull(int i) {
    int lson = i*2 + 1, rson = i*2 + 2;
    ST[i].data = ST[lson].data + ST[rson].data;
    ST[i].data %= p;
}
void push(int i, int l, int r) {
    if (l != r) {
        int m = (l+r) / 2;
        int lson = i*2 + 1, rson = i*2 + 2;
        ST[lson].chg += ST[i].chg;
        ST[rson].chg += ST[i].chg;
        ST[lson].data += ST[i].chg * (m-l+1);
        ST[rson].data += ST[i].chg * (r-m);

        ST[lson].chg %= p;
        ST[rson].chg %= p;
        ST[lson].data %= p;
        ST[rson].data %= p;
    }
    ST[i].chg = 0;
}
void add(int ql, int qr, int i, int l, int r, ll x) {
    // query left, query right, node idx, range left, range right, plus x
    if (ql <= l && qr >= r) {
        ST[i].chg += x;
        ST[i].data += x * (r-l+1);

        ST[i].chg %= p;
        ST[i].data %= p;
    }
    else if (qr < l || ql > r) {
        return ;
    }
    else {
        push(i, l, r);
        int m = (l+r) / 2;
        int lson = i*2 + 1, rson = i*2 + 2;
        add(ql, qr, lson, l, m, x);
        add(ql, qr, rson, m+1, r, x);
        pull(i);
    }
}
ll query(int ql, int qr, int i, int l, int r) {
    if (ql <= l && qr >= r) {
        return ST[i].data%p;
    }
    else if (qr < l || ql > r) return 0;
    else {
        push(i, l, r);
        int m = (l+r) / 2;
        int lson = i*2 + 1, rson = i*2 + 2;
        ll ans = query(ql, qr, lson, l, m) + query(ql, qr, rson, m+1, r);
        ans %= p;
        return ans;
    }
}

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
void modify(int x, int y, int z) {
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(r);
    id_cnt = 0;
    dfs2(r, r);
    for (int i = 1; i <= n; ++i) {
        add(id[i], id[i], 1, 1, n, arr[i]);
        debug(i, id[i]);
    }
    while (m--) {
        int opt, x, y, z;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> z;
            modify(x, y, z);
        }
        else if (opt == 2) {
            cin >> x >> y;
            cout << sum(x, y) << endl;
        }
        else if (opt == 3) {
            cin >> x >> z;
            add(id[x], id[x]+sz[x]-1, 1, 1, n, z);
        }
        else if (opt == 4) {
            cin >> x;
            cout << query(id[x], id[x]+sz[x]-1, 1, 1, n) << endl;
        }
        // for (int i = 1; i <= n; ++i) {
        //     debug(query(id[i], id[i], 1, 1, n));
        // }
    }
    return 0;
}

