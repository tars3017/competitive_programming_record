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
struct Status {
    int r, c, step;
    string path;
};
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
char dir_c[5] = {'D', 'R', 'U', 'L'};
bool vis[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            g[i].push_back(c);
        }
    }
    debug("here");
    bool Find = false;
    Status start;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'A') {
                start.r = i;
                start.c = j;
                start.step = 0;
                break;
            }
        }
    }
    queue<Status> q;
    q.push(start);
    while (!q.empty()) {
        Status now = q.front();
        q.pop();
        vis[now.r][now.c] = 1;
        debug(now.r, now.c);
        if (g[now.r][now.c] == 'B') {
            cout << "YES" << endl;
            cout << now.step << endl;
            cout << now.path << endl;
            return 0;
        }
        /* g[now.r][now.c] = '#'; */
        for (int i = 0; i < 4; ++i) {
            int nextR = now.r + dir[i][0];
            int nextC = now.c + dir[i][1];
            if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && g[nextR][nextC] != '#' && !vis[nextR][nextC]) {
                if (g[nextR][nextC] == 'B') {
                    cout << "YES" << endl;
                    cout << now.step+1 << endl;
                    now.path.push_back(dir_c[i]);
                    cout << now.path << endl;
                    return 0;
                }
                debug("push", nextR, nextC, g[nextR][nextC]);
                Status next;
                next.r = nextR, next.c = nextC;
                next.path = now.path;
                next.path.push_back(dir_c[i]); 
                next.step = now.step+1;
                q.push(next);
            }
        }
        /* for (int i = 0; i < n; ++i) { */
        /*     debug(g[i]); */
        /* } */
    }
    cout << "NO" << endl;
    Time();
    return 0;
}
