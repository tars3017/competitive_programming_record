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

int n, q;
ll ST[200005*2];
void upd(int k, ll x) {
    k += n;
    ST[k] = x;
    for (k /= 2; k > 0; k /= 2) {
        ST[k] = min(ST[k*2], ST[k*2+1]);
    }
}
int qry(int a, int b) {
    a += n, b += n;
    ll s = LLONG_MAX;
    while (a <= b) {
        if (a % 2 == 1) s = min(s, ST[a++]);
        if (b % 2 == 0) s = min(s, ST[b--]);
        a /= 2, b /= 2;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    memset(ST, 0x3f3f, sizeof(ST));
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        upd(i, num);
    }
    debug("here");
    while (q--) {
        int opt, a, b; cin >> opt >> a >> b;
        if (opt == 1) {
            upd(--a, b);
        }
        else {
            cout << qry(--a, --b) << endl;
        }
    }
    return 0;
}

