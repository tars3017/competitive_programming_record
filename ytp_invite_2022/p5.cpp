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

int cnt[105];
bool dp[3000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int d; cin >> d;
    int total = 0;
    for (int i = 1; i <= d; ++i) {
        int num; cin >> num;
        cnt[num]++;
        total += num;
    }
    vector<int> v;
    /* set<int> s; */
    for (int i = 1; i <= 100; ++i) {
        if (cnt[i] >= 2) {
            int x = 0, now_cnt = 0;
            debug(1<<x, cnt[i]/2);
            while ( now_cnt+(1<<x) <= cnt[i]/2 ) {
                v.push_back(i*(1<<x));
                /* s.insert(i*(1<<x)); */
                now_cnt += (1<<x);
                x++;
            }
            debug(cnt[i], now_cnt);
            for (int j = 0; j < cnt[i]/2-now_cnt; ++j) {
                v.push_back(i);
            }
        }
    }
    /* for (int i : v) { */
    /*     cout << i << '#'; */
    /* } */
    /* cout << endl; */
    dp[0] = 1;
    for (int i : v) {
        for (int j = total; j >= 1; --j) {
            if (j-i >= 0) {
                dp[j] |= dp[j-i];
                debug(j, dp[j], i, dp[j-i]);
            }
        }
    }
    /* for (int i = 1; i <= 100; ++i) { */
    /*     if (cnt[i] == 0) continue; */
    /*     for (int j = total; j >= 1; --j) { */
    /*         for (int k = 1; k <= (cnt[i]/2); ++k) { */
    /*             if (j-k*i >= 0) { */
    /*                 debug(j, k, cnt[i], j-k*i); */
    /*                 dp[j] |= dp[j-k*i]; */
    /*             } */
    /*         } */
    /*     } */
    /* } */
    ll ans = 0;
    for (int i = 0; i <= total; ++i) {
        if (dp[i]) {
            ans++;
            debug(i);
        }
    }
    cout << ans << endl;
    Time();
    return 0;
}

