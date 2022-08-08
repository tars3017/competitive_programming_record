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

pair<ll, int> arr[100005];
ll dp[100005];
pair<int, ll> arr2[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].F;
        arr[i].S = i;
    }
    sort(arr+1, arr+1+n);
    dp[n] = arr[n].F+k;
    for (int i = n-1; i > 0; --i) {
        dp[i] = arr[i].F + k;
        if (arr[i].F+k >= arr[i+1].F) {
            dp[i] = max(dp[i], dp[i+1]);
        }
        arr2[arr[i].S].F = arr[i].F;
        arr2[arr[i].S].S = dp[i];
    }
    while (p--) {
        int a, b; cin >> a >> b;
        cout << (arr2[a].S == arr2[b].S ? "Yes" : "No") << endl;
        /* ll a_value = arr2[a].F, a_dp = arr2[a].S; */
        /* ll b_value = arr2[b].F, b_dp = arr2[b].S; */
        /* if (a_value > b_value) { */
        /*     cout << (b_dp >= a_value ? "Yes" : "No") << endl; */
        /* } */
        /* else { */
        /*     cout << (a_dp >= b_value ? "Yes" : "No") << endl; */
        /* } */
    }
    Time();
    return 0;
}

