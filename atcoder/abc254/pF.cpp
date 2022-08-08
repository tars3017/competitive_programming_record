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

int a[200005], b[200005];
ll GCD(ll a, ll b) {
    if (b == 0) return a;
    return GCD(b, a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    while (q--) {
        ll ans = 0;
        int h1, h2, w1, w2; cin >> h1 >> h2 >> w1 >> w2;
        for (int i = h1; i <= h2; ++i) {
            for (int j = w1; j <= w2; ++j) {
                ll now = a[i] + b[j];
                if (ans == 0) ans = now;
                else ans = GCD(ans, now);
                debug(ans, now);
            }
        }
        cout << ans << endl;
    }
    Time();
    return 0;
}

