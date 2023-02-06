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

ll arr[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll c; cin >> c;
        for (ll i = 1; i <= n; ++i) {
            cin >> arr[i];
            arr[i] += i;
        }
        sort(arr+1, arr+n+1);
        int now = 1;
        int cnt = 0;
        while (now <= n && c >= arr[now]) {
            ++cnt;
            c -= arr[now];
            ++now;
        }
        cout << cnt << endl;
    }
    return 0;
}

