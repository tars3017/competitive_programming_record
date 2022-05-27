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

ll ST[200005*2];
int n, q; 
void upd(int k, int x) {
    k += n;
    ST[k] = x;
    for (k /= 2; k > 0; k /= 2) {
        ST[k] = ST[k*2] + ST[k*2+1];  
    }
}
ll qry(int l, int r) {
    l += n, r += n;
    ll s = 0;
    while (l <= r) {
        if (l % 2 == 1) s += ST[l++];  
        if (r % 2 == 0) s += ST[r--];
        l /= 2, r /= 2;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll num; cin >> num;
        upd(i, num);
    }
    // for (int i = 1; i <= 2*n; i++) {
    //     cout << ST[i] << '*';
    // }
    // cout << endl;
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

