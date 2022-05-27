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

bool connected[100005];
vector<int> graph[100005];
ll n, m, c_lib, c_road; 
ll cur;
void dfs(const int &now) {
    debug(now);
    connected[now] = true;
    for (auto i : graph[now]) {
        if (!connected[i]) {
            cur += c_road;
            dfs(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin >> q;
    while (q--) {
        memset(connected, 0, sizeof(connected));
        cin >> n >> m >> c_lib >> c_road;
        for (int i = 0; i <= n; i++) graph[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (c_road > c_lib) {
            cout << c_lib*n << endl;
        }
        else {
            ll ans = 0;
            for (int i = 1; i <= n; i++) {
                if (!connected[i]) {
                    cur = c_lib;
                    dfs(i);
                    debug(cur);
                    ans += cur;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

