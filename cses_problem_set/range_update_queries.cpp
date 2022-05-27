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
void upd(int a, int b, ll x) {
    a += n, b += n;
    while (a <= b) {
        if (a % 2 == 1) {
            ST[a++] += x;
        }
        if (b % 2 == 0) {
            ST[b--] += x;
        }
        a /= 2, b /= 2;
    }
}
ll qry(int k) {
    k += n;
    ll s = ST[k];
    for (k /= 2; k > 0; k /= 2) {
        s += ST[k];
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        upd(i, i, num); 
    }
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int a, b, x; cin >> a >> b >> x;
            upd(--a, --b, x);
        }
        else {
            int k; cin >> k;
            cout << qry(--k) << endl;
        }
    }
    return 0;
}

