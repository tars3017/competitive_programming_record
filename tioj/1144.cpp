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

struct Pos {
    int idx[5];
    int v;
    Pos(int _a=0, int _b=0, int _c=0, int _v=0) {
        idx[0] = _a;
        idx[1] = _b;
        idx[2] = _c;
        v = _v;
    }
};
int table[205][205];
int dp[205][205][2];
vector<int> seq;
const int INF = 1<<30;
int arr[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> table[i][j];
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    /* string tmp; getline(cin, tmp); */
    /* getline(cin, tmp); */
    /* stringstream ss; */
    /* ss << tmp; */
    /* int num; */
    /* while (ss >> num) { */
    /*     seq.push_back(num); */
    /* } */ 
    for (m = 0; cin >> arr[m]; m++); 
    /* int n = seq.size(); */
    dp[2][3][0] = dp[3][2][0] = table[1][arr[0]];
    dp[3][1][0] = dp[1][3][0] = table[2][arr[0]];
    dp[1][2][0] = dp[2][1][0] = table[3][arr[0]];
    debug(dp[2][3][0], dp[1][2][0], dp[1][3][0], arr[0]);
    int pos = 0;
    for (int k=0; k < m-1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                /* debug(dp[k][j][ctl^1], dp[k][seq[i-1]][ctl^1], dp[seq[i-1]][j][ctl^1]); */
                /* debug(j, k, ctl, dp[j][k][ctl^1], dp[j][k][ctl], seq[i-1], seq[i], table[seq[i-1]][seq[i]]); */
                dp[i][j][pos^1] = min(dp[i][j][pos^1], dp[i][j][pos]+table[arr[k]][arr[k+1]]);
                dp[i][arr[k]][pos^1] = min(dp[i][arr[k]][pos^1], dp[i][j][pos]+table[j][arr[k+1]]);
                dp[arr[k]][j][pos^1] = min(dp[arr[k]][j][pos^1], dp[i][j][pos]+table[i][arr[k+1]]);
                dp[i][j][pos] = INF;

                /* dp[j][k][ctl^1] = dp[k][j][ctl^1]; */
                /* dp[k][seq[i-1]][ctl^1] = dp[seq[i-1]][k][ctl^1]; */
                /* dp[j][seq[i-1]][ctl^1] = dp[seq[i-1]][j][ctl^1]; */ 
                /* dp[i][j][ctl] = INF; */
            }
        }
        pos ^= 1;
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            /* if (i == j) continue; */
            ans = min(ans, dp[i][j][pos]);
        }
    }
    cout << ans << endl;
    Time();
    return 0;
}

