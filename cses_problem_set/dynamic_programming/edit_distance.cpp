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

int dp[5005][5005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b; cin >> a >> b;
    dp[1][0] = dp[0][1] = 1;
    for (int j = 2; j <= b.size(); j++) dp[0][j] = j; 
    for (int i = 2; i <= a.size(); i++) dp[i][0] = i; 
    // if (a[0] != b[0]) dp[1][1] = 1;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            // if (i == 0 && j == 0) continue;
            dp[i+1][j+1] = (a[i] == b[j] ? dp[i][j] : dp[i][j]+1);
            debug(i+1, j+1, dp[i][j], dp[i+1][j], dp[i][j+1], a[i], b[i]);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1]+1);
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j]+1);
        }
    }
    // for (int i = 0; i <= a.size(); ++i) {
    //     for (int j = 0; j <= b.size(); ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}

