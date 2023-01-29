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

vector<int> v;
bool dp[30][60005];
int main() {
    // 42min
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        v.clear();
        memset(dp, 0, sizeof(dp));
        stringstream ss;
        ss << str;
        int num;
        ll total = 0;
        v.push_back(0);
        while (ss >> num) {
            v.push_back(num);
            total += num;
        }
        int n = v.size()-1;
        dp[0][0] = 1;
        for (int i = 1; i < v.size(); ++i) {
            for (int j = 0; j <= total; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j-v[i] >= 0) {
                    dp[i][j] |= dp[i-1][j-v[i]];
                }
            }
        }
        ll ans = 0;
        for (ll i = total; i > 0; --i) {
            if (dp[n][i]) {
                debug(i);
                ans = max(ans, i * (total-i)); 
            }
        }
        cout << ans << endl;
    }
    Time();
    return 0;
}

