#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do{\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0);
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

struct Node {
    int p;
    bool dir;
    Node(int _p, int _d): p(_p), dir(_d){}
    bool operator < (const Node &other) {
        return p < other.p;
    }
    bool operator == (const Node &other) {
        return p == other.p;
    }
};
bool cmp(Node a, Node b) {
    return a.p < b.p;
}
int n;
map<int, vector<Node>> x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x_tmp, y_tmp;
        bool t;
        cin >> x_tmp >> y_tmp >> t;
        x[x_tmp].push_back(Node(y_tmp, t));
        y[y_tmp].push_back(Node(x_tmp, t));
    }
    for (auto &now : x) {
        sort(now.S.begin(), now.S.end(), cmp);
    }
    for (auto &now : y) {
        sort(now.S.begin(), now.S.end(), cmp);
    }
    int dir = 0; // 0 | 1 | 2 | 3     > | v | < | ^
    int a = 0, b = 0;
    int cnt = 0;
    while (1) {
        cnt++;
        if (dir == 0) {
            int pos = upper_bound(y[b].begin(), y[b].end(), Node(a, 0)) - y[b].begin();
            if (pos == y[b].size()) break;
            a = y[b][pos].p;
            if (y[b][pos].dir == 0) {
                dir = 3;
            }
            else {
                dir = 1;
            }
        }
        // else if (dir == 2) {
        //     int pos = lower_bound(y[b].begin(), y[b].end(), a) - y[b].begin();
        //     if (pos == 0) break;
        //     a = y[b][pos-1].p;
        //     if (y[b][pos].dir == 0) {
        //         dir = 1;
        //     }
        //     else {
        //         dir = 3;
        //     }
        // }
        // else if (dir == 1) {
        //     int pos = lower_bound(x[a].begin(), x[a].end(), b) - x[a].begin();
        //     if (pos == 0) break;
        //     b = x[a][pos-1].p;
        //     if (x[a][pos].dir == 0) {
        //         dir = 2;
        //     }
        //     else {
        //         dir = 0;
        //     }
        // }
        // else {
        //     int pos = upper_bound(x[a].begin(), x[a].end(), b) - x[a].begin();
        //     if (pos == x[a].size()) break;
        //     b = x[a][pos].p;
        //     if (x[a][pos].dir == 0) {
        //         dir = 0;
        //     }
        //     else {
        //         dir = 2;
        //     }
        // }
    }
    cout << cnt << endl;
    Time()
    return 0;
}

