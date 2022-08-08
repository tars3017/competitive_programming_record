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
struct DisjoinSet {
    int p[10005];
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }
    int Find(int x) {
        return (p[x] == x ? x : p[x] = Find(p[x]));
    }
    void Union(int a, int b) {
        p[Find(a)] = Find(b);
    }
}djs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    djs.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        djs.Union(a, b);
    }
    for (int i = 0; i < q; ++i) {
        int p, q; cin >> p >> q;
        if (djs.Find(p) == djs.Find(q)) {
            cout << ":)" << endl;
        }
        else {
            cout << ":(" << endl;
        }
    }
    Time();
    return 0;
}

