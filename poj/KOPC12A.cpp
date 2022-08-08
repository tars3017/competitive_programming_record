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

int height[10005];
int cost[10005];
int n;
ll f(int k) {
    ll test_cost = 0;
    for (int i = 1; i <= n; ++i) {
        test_cost += abs(height[i]-k) * cost[i];
    }
    return test_cost;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        int l = 0, r = 0; 
        for (int i = 1; i <= n; ++i) {
            cin >> height[i];
            r = max(r, height[i]);
        }
        for (int i = 1; i <= n; ++i) {
            cin >> cost[i];
        }
        while (l < r-1) {
            int ml = l + (r-l)/3;
            int mr = l + (r-l)*2/3;
            debug(l, ml, mr, r);
            if (f(ml) < f(mr)) {
                r = mr-1;
            }
            else {
                l = ml+1;
            }
        }
        debug(l, r);
        cout << min(f(l), max(f(l+1), f(r))) << endl;
    }
    Time();
    return 0;
}

