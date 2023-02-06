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

// segment tree(range update range query)
struct Node {
    ll data, chg;
}ST[100005*4];
void pull(int i) {
    int lson = i*2 + 1, rson = i*2 + 2;
    ST[i].data = ST[lson].data + ST[rson].data;
}
void push(int i, int l, int r) {
    if (l != r) {
        int m = (l+r) / 2;
        int lson = i*2 + 1, rson = i*2 + 2;
        ST[lson].chg += ST[i].chg;
        ST[rson].chg += ST[i].chg;
        ST[lson].data += ST[i].chg * (m-l+1);
        ST[rson].data += ST[i].chg * (r-m);
    }
    ST[i].chg = 0;
}
void add(int ql, int qr, int i, int l, int r, int x) {
    // query left, query right, node idx, range left, range right, plus x
    if (ql <= l && qr >= r) {
        ST[i].chg += x;
        ST[i].data += x * (r-l+1);
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
        return ST[i].data;
    }
    else if (qr < l || ql > r) return 0;
    else {
        push(i, l, r);
        int m = (l+r) / 2;
        int lson = i*2 + 1, rson = i*2 + 2;
        int ans = query(ql, qr, lson, l, m) + query(ql, qr, rson, m+1, r);
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    add(1, 3, 1, 1, 6, 2);
    add(3, 5, 1, 1, 6, 3);
    for (int i = 1; i <= 6; ++i) {
        cout << query(i, i, 1, 1, 6) << endl;
    }
    cout << endl;
    cout << query(1, 3, 1, 1, 6) << endl;
    cout << query(2, 6, 1, 1, 6) << endl;
    return 0;
}

