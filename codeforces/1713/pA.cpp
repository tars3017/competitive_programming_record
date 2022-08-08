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

vector<int> y_axis, x_axis;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll max_x = 0, max_y = 0;
        ll min_x = 0, min_y = 0;
        ll n; cin >> n;
        for (int i = 0; i < n; ++i) {
            ll x, y; cin >> x >> y;
            max_x = max(x, max_x);
            max_y = max(y, max_y);
            
            min_x = min(x, min_x);
            min_y = min(y, min_y);
        }
        cout << ( abs(min_x) + abs(max_x) + abs(min_y) + abs(max_y) ) * 2 << endl; 
    }
    Time();
    return 0;
}

