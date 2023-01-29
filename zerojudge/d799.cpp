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

int n;
ll arr[500005];
struct node {
    ll val;
    node *l, *r;
    ll tag;
    node(int v): val(v), l(0), r(0), tag(0) {}
    void pull() { val = l->val + r->val; }
};
node* build(int l, int r, node* p) {
    if (l == r) {
        return new node(arr[l]);
    }
    int m = (l+r) / 2;
    p = new node(0);
    p->l = build(l, m, p->l);
    p->r = build(m+1, r, p->r);
    p->pull();
    return p;
}
void push(int l, int r, node* p) {
    if (!p->tag) return ;
    if (l != r)  { // check leaf
        int m = (l+r) / 2;
        p->l->tag += p->tag;
        p->r->tag += p->tag;
        p->l->val += p->tag * (m-l+1);
        p->r->val += p->tag * (r-m);
    }
    p->tag = 0;
}
void modify(int ql, int qr, int l, int r, node* p, int k) {
    if (qr < l || ql > r) return ;
    else if (ql <= l && qr >= r) {
        p->tag += k;
        p->val += k * (r-l+1);
        return ;
    }
    push(l, r, p);
    int m = (l+r) / 2;

    // line 55 so don't need if else
    modify(ql, qr, l, m, p->l, k);
    modify(ql, qr, m+1, r, p->r, k);
    p->pull();
}
ll query(int ql, int qr, int l, int r, node* p) {
    if (qr < l || ql > r) return 0;
    else if (ql <= l && qr >= r) {
        return p->val;
    }
    push(l, r, p);
    int m = (l+r) / 2;
    ll left = query(ql, qr, l, m, p->l);
    ll right = query(ql, qr, m+1, r, p->r);
    return left + right;
}
int main() {
    // 14 07
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    node* root;
    root = build(1, n, 0);
    int q; cin >> q;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1)  {
            int a, b, k; cin >> a >> b >> k;
            modify(a, b, 1, n, root, k);
        } 
        else {
            int a, b; cin >> a >> b;
            cout << query(a, b, 1, n, root) << endl;
        }
    }
    Time();
    return 0;
}

