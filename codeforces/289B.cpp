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

/* int arr[105][105]; */
map<int, int> mp;
vector<pii> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, d; cin >> n >> m >> d;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int num; cin >> num;
            mp[num]++;
            /* cin >> arr[i][j]; */
        }
    }
    bool able = true;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        v.push_back({iter->F, iter->S});
    }
    for (int i = 1; i < v.size(); ++i) {
        if ( (v[i].F-v[i-1].F) % d != 0) {
            able = false;
            break;
        }
    }
    if (!able) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = LLONG_MAX;
    for (int k = 0; k < v.size(); ++k) {
        ll cur = 0;
        for (int i = 0; i < v.size(); ++i) {
            cur += abs(v[k].F-v[i].F)*v[i].S/d;
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    Time();
    return 0;
}

