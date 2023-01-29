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
    ll a, b; cin >> a >> b;
    ll n; cin >> n;
    n %= 6;
    ll ans = 0;
    if (n == 1) ans = a;
    else if (n == 2) ans = b;
    else if (n == 3) ans = b-a;
    else if (n == 4) ans = -a;
    else if (n == 5) ans = -b;
    else ans = -b+a;

    ll mod = 1e9 + 7;
    if (ans < 0) ans += mod;
    if (ans < 0) ans += mod;
    cout << (ans%mod) << endl;
    Time();
    return 0;
}

