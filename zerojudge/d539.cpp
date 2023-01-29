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

int n, m; 
int arr[500005];
int sparse_table[1<<20][20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    debug(1<<19);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sparse_table[i][0] = arr[i];
    }
    debug(sparse_table[6][0]);
    for (int i = 1; i <= 19; ++i) {
        for (int j = 1; j <= n; ++j) {
            sparse_table[j][i] = max(sparse_table[j][i-1], sparse_table[j+(1 << (i-1) )][i-1]);
        }
    }
    debug(sparse_table[6][0]);
    cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        if (l == r) {
            cout << sparse_table[l][0] << endl;
            continue;
        }
        int p = (log(r-l+1) / log(2));
        cout << max(sparse_table[l][p], sparse_table[r-(1<<p)+1][p]) << endl;
    }
    Time();
    return 0;
}

