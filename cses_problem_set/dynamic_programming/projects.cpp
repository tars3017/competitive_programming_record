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

int n;
struct project {
    ll start, end, p;
    project(ll _s=0, ll _e=0, ll _p=0): start(_s), end(_e), p(_p){};
};
bool cmp(project a, project b) {
    if (a.end != b.end) 
        return a.end < b.end;
    return a.start < b.start;
}
project arr[200005];
ll dp[200005];
map<int, int> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b, p; cin >> a >> b >> p;
        // mp[a], mp[b];
        arr[i] = project(a, b, p);
    }
    // int now = 1;
    // for (auto iter = mp.begin(); iter != mp.end(); iter++) {
    //     iter->S = now++;
    //     debug(iter->F, iter->S);
    // }
    sort(arr+1, arr+1+n, cmp);
    dp[1] = arr[1].p;
    for (int i = 2; i <= n; ++i) {
        // dp[ mp[arr[i].end] ] = max( dp[ mp[arr[i].end] ], dp[ mp[arr[i].start] ] + arr[i].p); 
        dp[i] = dp[i-1];
        int j = i-1;
        while (j > 0 && arr[j].end >= arr[i].start) --j;
        debug(j, arr[j].end, arr[i].start);
        if (j > 0) dp[i] = max(dp[i], dp[j]+arr[i].p); 
        // debug(i, arr[i].start, arr[i].end, arr[i].p, mp[arr[i].end]);
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << dp[n] << endl;
    return 0;
}

