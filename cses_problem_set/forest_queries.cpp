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

int n, q; 
int pre[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j-1] == '*') {
                debug(i, j, pre[i-1][j], pre[i][j-1], pre[i-1][j-1]);
                pre[i][j] = pre[i-1][j] + pre[i][j-1] + 1 - pre[i-1][j-1];
            }
            else {
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) 
    //         cout << pre[i][j] << ' ';
    //     cout << endl;
    // }
    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        int max_y = max(y1, y2), max_x = max(x1, x2);
        int min_y = min(y1, y2), min_x = min(x1, x2);
        debug(max_y, max_x, min_y, min_x);
        cout << pre[max_y][max_x] - pre[max_y][min_x-1] - pre[min_y-1][max_x] + pre[min_y-1][min_x-1] << endl; 
    }
    return 0;
}

