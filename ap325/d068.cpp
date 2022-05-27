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
ll arr[100005] = {};
ll dp[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2] + min(arr[0], arr[1]);
    for (int i = 3; i < n; i++) {
        dp[i] = min(dp[i-1], min(dp[i-2], dp[i-3])) + arr[i];
    }
    if (n == 1) {
        cout << dp[0] << endl;
    }
    else 
        cout << min(dp[n-1], dp[n-2]) << endl;
    return 0;
}

