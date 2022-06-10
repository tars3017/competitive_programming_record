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

ll pre[200005];
ll arr[200005];
ll n, q; 
struct Node {
    int chg, data;
}ST[200005*4];
void build(int i, int l, int r) {
    if (l == r) {
        debug(i, pre[l]);
        ST[i].data = pre[l];
        return ;
    }
    int m = (l+r) / 2, lson = i*2+1, rson = i*2+2;
    build(lson, l, m);
    build(rson, m+1, r);
    ST[i].data = max(ST[lson].data, ST[rson].data);  
}
void add(int a, int b, int i, int l, int r, ll x) {
    if (a <= l && r <= b) {
        debug(i, l, r, x);
        ST[i].chg += x;
    }
    else if (r < a || b < l) return ;
    else {
        int m = (l+r) / 2, lson = i*2+1, rson = i*2 + 2;
        add(a, b, lson, l, m, x);
        add(a, b, rson, m+1, r, x);
        ST[i].data = max(ST[lson].data+ST[lson].chg, ST[rson].data+ST[rson].chg);
    }
}
ll query(int a, int b, int i, int l, int r) {
    if (a <= l && r <= b) return ST[i].data+ST[i].chg;
    else if (r < a || b < l) return -1;
    else {
        int m = (l+r) / 2, lson = i*2+1, rson = i*2+2;
        ll x1 = query(a, b, lson, l, m);
        ll x2 = query(a, b, rson, m+1, r);
        return max(x1, x2) + ST[i].chg;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // pre[1] = 1;
    // pre[2] = 16;
    // pre[3] = 2;
    // pre[4] = 8;
    // pre[5] = 4;
    // n = 5;
    // Node* root = build(1, n);
    // modify(root, 1, n, 1, 4, 3);
    // for (int i = 1; i <= 5; i++) {
    //     cout << query(root, 1, n, i, i) << endl;
    // }
    cin >> n >> q;
    // h = sizeof(ll) * 8 - __builtin_clz(n);
    pre[0] = 0;
    for (ll i = 1; i <= n; i++) {
        ll num; cin >> num;
        arr[i] = num;
        pre[i] = pre[i-1] + num;
    }
    build(1, 1, n);
    while (q--) {
        int opt;
        ll a, b; cin >> opt >> a >> b;
        if (opt == 1) {
            add(a, n, 1, 1, n, b-arr[a]);
            arr[a] = b;
        }
        else {
            cout << max(query(a-1, b, 1, 1, n)-query(a-1, a-1, 1, 1, n), (long long)0) << endl; 
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << query(i, i, 1, 1, n) << ' ';
        // }
        // cout << endl;
    }
    return 0;
}

