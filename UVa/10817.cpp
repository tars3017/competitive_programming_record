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
#define MAXOBJ 8
int cost[105][1<<MAXOBJ][1<<MAXOBJ];
int s, n, m;
int teaching[105], salary[105];
ll dp(int now, int mask1, int mask2) {
    debug(now, mask1, mask2, cost[now][mask1][mask2]);
    if ( cost[now][mask1][mask2] != -1) return cost[now][mask1][mask2];
    bool skip = false;
    int tmp1 = mask1, tmp2 = mask2;
    for (int i = 0; i < s; i++) {
        if ( ((1<<i) & mask1 == 0) && ((1<<i) & mask2 == 0)) {
            skip = true;
            break;
        }
        else if ((1<<i) & tmp2) {
            tmp2 ^= (1<<i); 
        }
        else {
            tmp1 ^= (1<<i);
        }
    }
    if (skip) {
        debug("here");
        return dp(now-1, mask1, mask2);
    }
    else {
        debug("here2", tmp1, tmp2);
        return cost[now][mask1][mask2] = min( dp(now-1, tmp1, tmp2)+salary[now], dp(now-1, mask1, mask2) );
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s >> n >> m && s) {
        memset(cost, -1, sizeof(cost));
        memset(teaching, 0, sizeof(teaching));
        memset(salary, 0, sizeof(salary));
        ll now_cost = 0;
        int mask1 = 0, mask2 = 0;
        for (int i = 1; i <= n; i++) {
            int money; cin >> money;
            now_cost += money;
            string str;
            // getline(cin, str);
            getline(cin, str);
            stringstream ss;
            ss << str;
            int num;
            while (ss >> num) {
                if (mask1 & (1<<(num-1))) {
                    mask2 |= (1<<(num-1));
                }
                else {
                    mask1 |= (1<<(num-1));
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> salary[i];
            string str;
            // getline(cin, str);
            getline(cin, str);
            stringstream ss;
            ss << str;
            int num, cur1 = 0;
            while (ss >> num) {
                cur1 |= (1<<(num-1));
            }
            teaching[i] = cur1;
        }
        for (int i = 0; i < (1<<s); i++) {
            for (int j = 0; j < (1<<s); j++) {
                cost[0][i][j] = 0x3f3f3f3f;
            }
        }
        for (int i = 0; i <= mask1; i++) {
            for (int j = 0; j <= mask2; j++) {
                cost[0][i][j] = 0;
                debug(i, j);
            }
        }
        cout << dp(n, (1<<s)-1, (1<<s)-1)+now_cost << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << cost[i][0][0] << ' ' << cost[i][3][0] << ' ' << cost[i][3][3] << endl;
        // }
    }
    return 0;
}
