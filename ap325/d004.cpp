#include <bits/stdc++.h>
using namespace std;
//#define tars3017
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
long long arr[500005];
long long pre[500005];
ll n, k; 
ll divide(int l, int r, int lev) {
    debug(l, r, lev);
    if (lev > k || r-l < 2) return 0;
    long long now = l+1;
    ll min_v = 0;
    for (ll i = l; i <= r; i++) {
        min_v += arr[i] * (i-now);
    }
    ll last_v = min_v;
    debug(last_v);
    for (ll i = now+1; i < r; i++) {
        long long new_v = last_v + pre[i-1] - pre[l-1] - (pre[r]-pre[i-1]);
        debug(i, new_v, pre[i-1]-pre[l-1], pre[r]-pre[i-1]);
        if (abs(new_v) < abs(min_v)) {
            now = i;
            min_v = new_v;
        }
        last_v = new_v;
    }
    debug(l, r, now, min_v);
    return divide(l, now-1, lev+1) + divide(now+1, r, lev+1) + arr[now];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }
    cout << divide(1, n, 1) << endl;
    return 0;
}
