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
vector<pii> dp;
int from[500005];
/* int dp[500005]; */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int num;
    while (cin >> num) {
        v.push_back(num);
    }
    /* dp[0] = 1; */
    memset(from, -1, sizeof(from));
    dp.push_back({v[0], 0});
    for (int i = 1; i < v.size(); ++i) {
        /* int pos = upper_bound(dp.begin(), dp.end(), v[i], cmp) - dp.begin(); */
        int l = 0, r = dp.size()-1;
        while (l < r) {
            int mid = (l+r) / 2;
            if (v[i] > dp[mid].F) {
                l = mid+1;
            }
            else {
                r = mid;
            }
        }
        if (dp[r].F <= v[i]) r++;
        int pos = r;
        /* for (int k = 0; k < dp.size(); ++k) { */
        /*     cout << dp[k].F << '@'; */
        /* } */
        /* cout << endl; */
        debug(pos, v[i]);
        if (pos == 0) {
            dp[0] = {v[i], i};
            from[i] = -1; 
        }
        else if (pos == dp.size() && v[i] > dp[pos-1].F) {
            if (v[i] > dp[pos-1].F) {
                dp.push_back({v[i], i});
                from[i] = dp[pos-1].S;
            }
            /* else if (v[i] == dp[pos-1].F) { */
            /*     dp[pos-1].F = v[i]; */
            /*     dp[pos-1].S = i; */
            /* } */
        }
        else if (pos == dp.size()) {
            dp[pos-1].S = i;
            from[i] = dp[pos-2].S;
        }
        else {
            if (v[i] <= dp[pos].F) {
                from[i] = dp[pos-1].S;
                dp[pos].F = v[i];
                dp[pos].S = i;
            }
            else {
                debug("here");
                for (int k = 0; k < dp.size(); ++k) {
                    cout << dp[k].F << '@';
                }
                cout << endl;
                debug(i, v[i], pos, dp[pos].F);
            }
            /* dp[pos].F = min(dp[pos], v[i]); */ 
            /* from[i] = pos-1; */
        }
        /* int last = 0; */
        /* for (int j = 0; j < i; ++j) { */
        /*     if (v[i] > v[j] && dp[j]+1 >= dp[i]) { */
        /*         dp[i] = dp[j]+1; */
        /*         last = j; */
        /*         from[i] = j; */
        /*     } */
        /* } */
    }
    /* int tail = 0, val = dp[0]; */
    /* for (int i = 1; i < v.size(); ++i) { */
    /*     if (dp[i] >= val) { */
    /*         val = dp[i]; */
    /*         tail = i; */
    /*     } */
    /* } */


    /* for (int i = 0; i < dp.size(); ++i) { */
    /*     cout << dp[i].F << ' '; */
    /* } */
    /* cout << endl; */
    int tail = dp.back().S;
    vector<int> ans;
    for (int i = tail; i >= 0;) {
        ans.push_back(v[i]);
        if (from[i] == -1) break;
        i = from[i]; 
    }
    cout << ans.size() << endl << '-' << endl;
    for (int i = ans.size()-1; i >= 0; --i) {
        cout << ans[i] << endl;
    }
    Time();
    return 0;
}

