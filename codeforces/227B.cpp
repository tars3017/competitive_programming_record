#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do{\
    fprintf(stderr, "line: %d -(%s) = ", __line__, #__va_args__);\
    _do(__va_args__);\
}while(0)
template<typename i>void _do(i&&x){cerr<<x<<endl;}
template<typename i, typename...t>void _do(i&&x, t&&...tail) {
    cerr<<x<<", ";
    _do(tail...);
}
#define time() cerr << "time elapsed: " << 1.0*clock() / clocks_per_sec << " s.\n";
#else 
#define debug(...)
#define time()
#endif
#define f first
#define s second
#define pii pair<int, int>
#define ll long long

int pos[100005];
int qry[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num; cin >> num;
        pos[num] = i;
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> qry[i];
    }
    ll a = 0, b = 0;
    for (int i = 0; i < m; ++i) {
        a += pos[ qry[i] ];
        b += n - pos[ qry[i] ] + 1;
    }
    cout << a << ' ' << b << endl;
    time();
    return 0;
}

