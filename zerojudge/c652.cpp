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

ll arr[300005];
struct node {
    ll val, tag, mx;
    node *l, *r;
    node(ll v): val(v), tag(0), mx(v), l(0), r(0) {}
    void pull() {
        if (l == r) return ;
        val = l->val + r->val;
        mx = max(l->mx, r->mx);
    }
};
node* build(int l, int r, node *p) {
    if (l == r) {
        p = new node(arr[l]);
        return p;
    }
    int m = (l+r) / 2;
    p = new node(0);
    p->l = build(l, m, p->l);
    p->r = build(m+1, r, p->r);
    p->pull();
    return p;
}
ll m_query(int ql, int qr, int l, int r, node* p) {
    if (qr < l || ql > r) return 0;
    else if (ql <= l && qr >= r) {
        return p->mx;
    }
    int m = (l+r) / 2;
    return max( m_query(ql, qr, l, m, p->l), m_query(ql, qr, m+1, r, p->r) );
}
void modify(int k, int l, int r, node* p) {
    if (p->mx < 1) return ;
    if (l == r) {
        p->val = sqrt(p->val);
        p->mx = p->val;
        return ;
    }
    int m = (l+r) / 2;
    if (k <= m) {
        ll m_val = m_query(l, m, l, r, p);
        modify(k, l, m, p->l);
    }
    else {
        ll m_val = m_query(m+1, r, l, r, p);
        modify(k, m+1, r, p->r);

    }
    p->pull();
}
ll query(int ql, int qr, int l, int r, node* p) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && qr >= r) {
        return p->val;
    }
    int m = (l+r) / 2;
    ll lv = query(ql, qr, l, m, p->l);
    ll rv = query(ql, qr, m+1, r, p->r);
    return  lv+rv;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    node* root = build(1, n, 0);
    while (q--) {
        int ctl, a, b; cin >> ctl >> a >> b;
        if (ctl == 0) {
            cout << query(a, b, 1, n, root) << endl;
        }
        else {
            for (int i = a; i <= b; ++i) {
                /* if (m_query(i, b, 1, n, root) <= 1) break; */
                modify(i, 1, n, root);
            }
        }
        /* for (int i = 1; i <= n; ++i) { */
        /*     debug(query(i, i, 1, n, root), m_query(i, i, 1, n, root)); */
        /* } */
    }
    Time();
    return 0;
}

