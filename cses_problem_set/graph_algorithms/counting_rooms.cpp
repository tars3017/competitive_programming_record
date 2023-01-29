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

string g[1005];
bool vis[1005][1005];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int n, m; 
void dfs(int r, int c) {
    vis[r][c] = 1;
    for (int i = 0; i < 4; ++i) {
        int nextR = r+dir[i][0];
        int nextC = c+dir[i][1];
        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && g[nextR][nextC] == '.') {
            g[nextR][nextC] = '#';
            dfs(nextR, nextC);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && g[i][j] == '.') {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    Time();
    return 0;
}

