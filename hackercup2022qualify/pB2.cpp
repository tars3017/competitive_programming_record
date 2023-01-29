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

int r, c; 
char g[3005][3005];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        memset(g, 0, sizeof(g));
        cin >> r >> c;
        for (int j = 0; j <= c+1; ++j) {
            g[0][j] = '#';
            g[r+1][j] = '#';
        }
        for (int i = 0; i <= r+1; ++i) {
            g[i][0] = '#';
            g[i][c+1] = '#';
        }
        int tree_cnt = 0;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cin >> g[i][j];
                if (g[i][j] == '^') {
                    tree_cnt++;
                }
            }
        }
        bool able = true;
        if (tree_cnt) {
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int nextR = i + dir[k][0];
                        int nextC = j + dir[k][1];
                        if (g[nextR][nextC] == '#') {
                            cnt++;
                        }
                    }
                    if (g[i][j] != '#' && cnt < 3) {
                        g[i][j] = '^';
                    }
                }
            }
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    int cnt = 0;
                    if (g[i][j] != '^') continue;
                    for (int k = 0; k < 4; ++k) {
                        int nextR = i + dir[k][0];
                        int nextC = j + dir[k][1];
                        if (g[nextR][nextC] == '^') {
                            cnt++;
                        }
                    }
                    if (cnt < 2) {
                        able = false;
                        break;
                    }
                }
                if (!able) break;
            }
        }
        debug(tree_cnt);
        if (tree_cnt == 0) {
            cout << "Case #" << Case++ << ": " << "Possible" << endl;
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    cout << g[i][j];
                }
                cout << endl;
            }
        }
        else if (able) {
            cout << "Case #" << Case++ << ": " << "Possible" << endl;
            for (int i = 1; i <= r; ++i) {
                for (int j = 1; j <= c; ++j) {
                    cout << g[i][j];
                }
                cout << endl;
            }
        }
        else {
            cout << "Case #" << Case++ << ": " << "Impossible" << endl;
        }
    }
    Time();
    return 0;
}

