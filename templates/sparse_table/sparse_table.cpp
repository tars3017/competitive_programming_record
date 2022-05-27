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

#define MAXN 1005
struct Sparse_Table {
    // Range Minimum Quires
    int arr[MAXN];
    int spt[MAXN][MAXN]; 
    void build(int n) {
        memset(spt, 0, sizeof(spt));
        for (int i = 0; i < n; i++) {
            spt[i][i] = arr[i];
            // if (i+1 < n) {
            //     spt[i][i+1] = min(arr[i], arr[i+1]);
            // }
        }
        for (int i = 1; (1<<i) < n; i++) {
            int step = (1<<i) - 1;
            debug(step);
            for (int j = 0; j+step < n; j++) {
                debug(j, j+(step/2), j+(step/2)+1, j+step);
                spt[j][j+step] = min(spt[j][j + (step/2)], spt[j + (step/2) + 1][j+step]);
            }
        }
    }
    int query(int l, int r) {
        int k = (int)log2(r-l+1);
        int step = (1<<k);
        debug(step, l, l+step-1, r-step+1, r);
        return min(spt[l][l+step-1], spt[r-step+1][r]);
    }

}sptb;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sptb.arr[i]; 
    }
    sptb.build(n);
    cout << sptb.query(0, 5) << endl;
    return 0;
}

