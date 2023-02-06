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

struct DisjoineSet {
    int p[10005];
    void init(int n) {
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }
    int Find(int x) {
        if (p[x] == x) return x;
        p[x] = Find(p[x]);
        return p[x];
    }
    void Union(int a, int b) {
        int pa = Find(a);
        int pb = Find(b);
        if (pa > pb) swap(pa, pb);
        p[pb] = pa;
    }
}djs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        djs.init(n);
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            djs.Union(a, b);
        }
        int k; cin >> k;
        cout << djs.Find(k) << endl;
    }
    return 0;
}

