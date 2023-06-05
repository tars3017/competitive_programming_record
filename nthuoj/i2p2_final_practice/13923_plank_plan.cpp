#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char graph[1005][1005];
struct state {
    int x, y;
    int step;
    state(int _x = 0, int _y = 0, int _s = 0): x(_x), y(_y), step(_s) {}
};
bool vis[1005][1005];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
    int n, m; cin >> n >> m;
    int start_x, start_y;
    for (int i = 1; i <= n; ++i) {
        graph[i][0] = '#';
        graph[i][m+1] = '#';
        for (int j = 1; j <= m; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 'P') {
                start_x = i;
                start_y = j;
            }
        }
    }
    for (int j = 0; j <= m+1; ++j) {
        graph[0][j] = '#';
        graph[n+1][j] = '#';
    }
    // for (int i = 0; i <= n+1; ++i) {
    //     for (int j = 0; j <= m+1; ++j) {
    //         cout << graph[i][j];
    //     }
    //     cout << endl;
    // }
    queue<state> q;
    q.push(state(start_x, start_y, 0));
    bool reach = false;
    while (!q.empty()) {
        state now = q.front();
        vis[now.x][now.y] = true;
        q.pop();
        if (graph[now.x][now.y] == '@') {
            cout << now.step << endl;
            reach = true;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int next_x = now.x + dir[i][0];
            int next_y = now.y + dir[i][1];
            if (graph[next_x][next_y] != '#' && !vis[next_x][next_y]) {
                vis[next_x][next_y] = 1;
                q.push(state(next_x, next_y, now.step+1));
            }
        }
    }
    // for (int i = 0; i <= n+1; ++i) {
    //     for (int j = 0; j <= m+1; ++j) {
    //         cout << graph[i][j];
    //     }
    //     cout << endl;
    // }
    if (!reach) cout << -1 << endl;
    return 0;
}