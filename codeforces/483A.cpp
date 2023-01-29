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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll l, r; cin >> l >> r;
    bool able = false;
    for (ll i = l; i <= r; ++i) {
        for (ll j = i+1; j <= r; ++j) {
            for (ll k = j+1; k <= r; ++k) {
                if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) {
                    able = true;
                    cout << i << ' ' << j << ' ' << k << endl;
                    break;
                }
            }
            if (able) break;
        }
        if (able) break;
    }
    if (!able) cout << -1 << endl;
    return 0;
    Time();
    return 0;
}

