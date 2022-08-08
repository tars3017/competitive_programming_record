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
int coin[105];
bool dp[105][1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> coin[i];
        sum += coin[i];
    }
    dp[0][0] = true;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] |= dp[i-1][j];
            if (j-coin[i] >= 0) dp[i][j] |= dp[i-1][j-coin[i]];
            if (j && dp[i][j]) s.insert(j); 
        }
    }
    cout << s.size() << endl;
    for (auto i : s) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

