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

const int MAXN = 200;
int a[MAXN], b[MAXN];
int n, q;
ll ST[MAXN*2][MAXN], ST2[MAXN*2][MAXN];
/* struct Node { */
/*     int chg, data; */
/* }ST[200005*4]; */
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else if (a == 0) return b;
    return GCD(b, a%b);
}
void build(int i, int l, int r, int row) {
    if (l == r) {
        ST[i][row] = a[row] + b[l];
        return ;
    }
    int m = (l+r) / 2, lson = i*2, rson = i*2+1;
    build(lson, l, m, row);
    build(rson, m+1, r, row);
    ST[i][row] = GCD(ST[lson][row], ST[rson][row]);  
}
void build_2d(int i, int l, int r) {
    if (l == r) {
        for (int j = 1; j < 2*n; ++j) {
            ST2[i][j] = ST[i][j];
        }
    }
    else {
        int m = (l+r) / 2, lson = i*2, rson = i*2+1;
        build_2d(lson, l, m);
        build_2d(rson, m+1, r);
        for (int j = 1; j < 2*n; ++j) {
            ST2[i][j] = GCD(ST2[lson][j], ST2[rson][j]);
        }
    }
}
ll query_fnl(int a, int b, int i, int l, int r, int fix) {
    if (a <= l && r <= b) return ST2[fix][i];
    else if (r < a || b < l) return 0;
    else {
        int m = (l+r) / 2, lson = i*2, rson = i*2+1;
        ll x1 = query_fnl(a, b, lson, l, m, fix);
        ll x2 = query_fnl(a, b, rson, m+1, r, fix);
        return GCD(x1, x2);
    }
}
ll query(int a, int b, int i, int l, int r, int y1, int y2) {
    if (a <= l && r <= b) return query_fnl(y1, y2, 1, 1, n, i);
    else if (r < a || b < l) return 0;
    else {
        int m = (l+r) / 2, lson = i*2, rson = i*2+1;
        ll x1 = query(a, b, lson, l, m, y1, y2);
        ll x2 = query(a, b, rson, m+1, r, y1, y2);
        return GCD(x1, x2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        build(1, 1, n, i);
    }
    build_2d(1, 1, n);
    while (q--) {
        int h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        cout << query(w1, w2, 1, 1, n, h1, h2) << endl;
    }
    return 0;
}

