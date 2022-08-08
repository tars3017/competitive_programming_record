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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 5;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        if (x == 0) cout << 1 << endl;
        else {
            ll now = 1;
            for (ll j = 1; j <= x; ++j) {
                now *= j;
                debug(now);
                while (now > 0 && (now%10 == 0)) {
                    now /= 10;
                }
                now %= 10;
                debug(now);
            }
            cout << (now%10) << endl;
        }
    }
    Time();
    return 0;
}
