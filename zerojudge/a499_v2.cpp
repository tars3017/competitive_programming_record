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

int arr[2005];
int dp_cnt[2005];
int dp_wei[2005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // reference https://mypaper.pchome.com.tw/zerojudge/post/1323263185
    int n, k, m; cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) {
        dp_cnt[i] = n+1;
        dp_wei[i] = 0xffffff;
        cin >> arr[i];
    }
    /* sort(arr+1, arr+1+n); */
    /* if (dp_wei[0]+arr[1] > m) { */
    /*     cout << 0 << endl; */
    /*     return 0; */
    /* } */
    dp_cnt[0] = 1;
    dp_wei[0] = 0;
    /* dp_wei[1] = arr[1]; */
    /* dp_cnt[1] = 1; */
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > m) continue;
        for (int j = i; j >= 0; --j) {
            debug(i, arr[i], j);
            if (dp_wei[j] + arr[i] > m) {
                debug("A");
                if (dp_cnt[j]+1 < dp_cnt[j+1] || (dp_cnt[j]+1 == dp_cnt[j+1] && arr[i] < dp_wei[j+1]) ) {
                    if (dp_cnt[j] + 1 > k) continue;
                    dp_cnt[j+1] = dp_cnt[j] + 1;
                    dp_wei[j+1] = arr[i];
                }
            }
            else {
                debug("B");
                if (dp_cnt[j] < dp_cnt[j+1] || (dp_cnt[j] == dp_cnt[j+1] && dp_wei[j]+arr[i] < dp_wei[j+1]) ) {
                    dp_cnt[j+1] = dp_cnt[j];
                    dp_wei[j+1] = dp_wei[j] + arr[i];
                }
            }
        }
    }
    for (int i = n; i >= 0; --i) {
        if (dp_cnt[i] != n+1) {
            debug(dp_cnt[i], dp_wei[i]);
            cout << i << endl;
            return 0;
        }
    }
    Time();
    return 0;
}

