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
int a, b;
char g[1005][1005];
bool vis[1005][1005];
int dir[5][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
void dfs(int r, int c) {
    vis[r][c] = 1;
    if (g[r][c] == '#') return ;
    else if (g[r][c] == 'A') a++;
    else if (g[r][c] == 'B') b++;
    for (int i = 0; i < 4; ++i) {
        int nr = r+dir[i][0], nc = c+dir[i][1];
        if (g[nr][nc] != '#' && !vis[nr][nc]) {
            dfs(nr, nc);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i <= n+1; ++i) g[i][0] = '#', g[i][m+1] = '#';
        for (int j = 0; j <= m+1; ++j) g[0][j] = '#', g[n+1][j] = '#';
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> g[i][j];
            }
        }
        memset(vis, 0, sizeof(vis));
        bool able = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!vis[i][j]) {
                    a = 0, b = 0;
                    dfs(i, j);
                    if (a != b) {
                        able = false;
                        break;
                    }
                }
            }
            if (!able) break;
        }
        cout << (able ? "YES" : "NO") << endl;
    }
    Time();
    return 0;
}

