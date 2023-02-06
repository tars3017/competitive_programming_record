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

int p[100005];
int a[100005];
int idx[100005];
// bool fixed[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, d; cin >> n >> m >> d;
        memset(p, 0, sizeof(p));
        memset(a, 0, sizeof(a));
        memset(idx, 0, sizeof(idx));
        // memset(fixed, 0, sizeof(fixed));
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            idx[p[i]] = i;
        }
        for (int i = 1; i <= m; ++i) {
            cin >> a[i];
        }
        int ans1 = 0x3f3f3f3f;
        for (int i = 1; i < m; ++i) {
            debug(idx[a[i]], idx[a[i+1]]);
            if (idx[a[i+1]] < idx[a[i]] || idx[a[i+1]] > idx[a[i]] + d) {
                debug("here");
                ans1 = 0;
                break;
            }

            if (d < n-1) {
                ans1 = min(ans1, abs(d-idx[a[i+1]]+idx[a[i]])+1);
            }
            ans1 = min(ans1, abs(idx[a[i+1]]-idx[a[i]]));
        }
        cout << ans1 << endl;
    }


    return 0;
}

