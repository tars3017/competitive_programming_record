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
ll A(ll x) {
    ll now = 0;
    for (ll i = 1; i <= x; i++) {
        now ^= i;
    }
    return now;
}
ll fun(ll x) {
    ll now = 0;
    for (ll i = 1; i <= x; i++) {
        now ^= A(i); 
    }
    return now;
}
ll q_fun(ll x) {
    ll now = x % 8;
    if (now == 1 || now == 0) return x;
    else if (now == 2 || now == 3) return 2;
    else if (now == 4 || now == 5) return x+2;
    else if (now == 6 || now == 7) return 0;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // for (int i = 1; i <= 20; i++) {
    //     cout << i << ' ' << fun(i) << endl;
    // }
    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << (q_fun(r) ^ q_fun(l-1)) << endl;
    }
    return 0;
}

