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

ll arr[1000005];
ll dp[1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    deque< pair<ll, int> > dq;
    dq.push_back({arr[1], 1});
    for (int i = 2; i <= n; ++i) {
        ll v = LLONG_MAX;
        if (i-k < 1) {
            v = 0;
            debug(i);
        }
        /* for (int j = max(1, i-k); j < i; ++j) { */
        /*     v = min(v, dp[j]); */
        /* } */
        while (!dq.empty() && dq.front().S < i-k) dq.pop_front();
        v = min(v, dq.front().F);
        dp[i] = v + arr[i];
        while (!dq.empty() && dq.back().F > dp[i]) {
            dq.pop_back();
        }
        dq.push_back({dp[i], i});
    }
    ll ans = LLONG_MAX;
    for (int i = n-k+1; i <= n; ++i) {
        debug(i, dp[i]);
        ans = min(ans, dp[i]);
    }
    for (int i = 1; i <= n; ++i) {
        debug(i, dp[i]);
    }
    cout << ans << endl;
    Time();
    return 0;
}

