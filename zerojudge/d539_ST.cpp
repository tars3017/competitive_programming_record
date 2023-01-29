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
    int val;
    Node *l, *r;
    Node(int v): val(v), l(nullptr), r(nullptr) {}
    void pull() {val = max(l->val, r->val);}
};
int arr[500005];
Node* build(int l, int r, Node* p) {
    if (l == r) return new Node(arr[l]);
    int mid = (l+r) / 2;
    p = new Node(0);
    p->l = build(l, mid, p->l);
    p->r = build(mid+1, r, p->r);
    p->pull();
    return p;
}
int query(int ql, int qr, int l, int r, Node* p) {
    if (ql > r || qr < l) return 0;
    else if (ql <= l && qr >= r) return p->val;
    int mid = (l+r) / 2;
    if (qr <= mid) {
        return query(ql, qr, l, mid, p->l);
    }
    else if (ql > mid) {
        return query(ql, qr, mid+1, r, p->r);
    }
    else {
        return max( query(ql, qr, l, mid, p->l), 
                    query(ql, qr, mid+1, r, p->r) );
    }
}
void modify(int x, int l, int r, Node* p, int v) {
    if (l == r) {
        p->val = v;
        return ;
    }
    int mid = (l+r) / 2;
    if (x <= mid) {
        modify(x, l, mid, p->l, v);
    }
    else {
        modify(x, mid+1, r, p->r, v);
    }
    p->pull();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    Node* root = build(1, n, 0);
    int m; cin >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        cout << query(a, b, 1, n, root) << endl;
    }
    Time();
    return 0;
}

