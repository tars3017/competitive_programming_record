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
int dp[500005];
int main() {
    // reference from yuihuang.com/dp-lis
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    dp[0] = 1;
    vector<int> opt;
    opt.push_back(v[0]);
    int len = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > opt.back()) {
            opt.push_back(v[i]);
            len++;
            dp[i] = len;
        }
        else {
            auto it = lower_bound(opt.begin(), opt.end(), v[i]);
            *it = v[i];
            dp[i] = (int)(it - opt.begin() + 1);
            debug(i, dp[i]);
        }
        /* for (int j : opt) { */
        /*     cout << j << '@'; */
        /* } */
        /* cout << endl; */
    }
    cout << len << endl << '-' << endl;
    vector<int> ans;
    int now_len = len;
    for (int i = v.size()-1; i >= 0; --i) {
        debug(i, dp[i], now_len);
        if (dp[i] == now_len) {
            debug(i);
            ans.push_back(v[i]);
            now_len--;
        }
    }
    for (int i = ans.size()-1; i >= 0; --i) {
        cout << ans[i] << endl;
    }
    Time();
    return 0;
}

