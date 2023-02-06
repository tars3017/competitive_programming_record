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

ll arr[200005];
ll table[200005][7];
ll diff[200005];
ll pre[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(table, 0, sizeof(table));
        memset(diff, 0, sizeof(diff));
        memset(pre, 0, sizeof(pre));
        int n, q; cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            table[i][0] = arr[i];
            ll now = arr[i];
            ll tmp = 0;
            for (int j = 1; j <= 3; ++j) {
                tmp = 0;
                while (now > 0) {
                    tmp += (now%10);
                    now /= 10;
                }
                table[i][j] = tmp;
                now = tmp;
            }
            assert(tmp < 10);
        }
        for (int i = 0; i < q; ++i) {
            int opt, l, r; cin >> opt;
            if (opt == 1) {
                cin >> l >> r;
                for (int j = l; j <= n; j += j&-j) {
                    ++diff[j];
                }
                for (int j = r+1; j <= n; j += j&-j) {
                    --diff[j];
                }
                // diff[l]++;
                // diff[r+1]--;
            }
            else {
                int x;
                cin >> x; 
                ll res = 0;
                for (int j = x; j > 0; j -= j&-j) {
                    res += diff[j];
                }
                cout << table[x][res] << endl;
            }
        }
    }
    return 0;
}

