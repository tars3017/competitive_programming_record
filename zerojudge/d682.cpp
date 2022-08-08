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

vector< vector<int> > cost;
vector< vector<int> > battle;
ll dp[55][5005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n, p; cin >> m >> n >> p;
    cost.resize(n+1, vector<int>(p+1));
    battle.resize(n+1, vector<int>(p+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= p; ++j) {
            cin >> cost[i][j] >> battle[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 5000; ++j) {
            if (j)
                dp[i][j] = 0x3f3f3f3f;
            else 
                dp[i][0] = 0;
        }
    }
    debug(dp[0][0]); 
    for (int i = 1; i <= p; ++i) { dp[1][battle[1][i]] = min(dp[1][battle[1][i]], (ll)cost[1][i]);
    }
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 5000; ++j) {
            dp[i][j] = dp[i-1][j];
            for (int k = 1; k <= p; ++k) {
                if (j-battle[i][k] >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-battle[i][k]]+cost[i][k]);
                }
            }
        }
    }
    for (int j = 5000; j >= 0; --j) {
        if (dp[n][j] <= m) {
            debug(dp[n][j]);
            cout << j << endl;
            break;
        }
    }
    Time();
    return 0;
}

