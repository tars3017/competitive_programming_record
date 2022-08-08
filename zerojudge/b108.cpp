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

vector<int> graph[10005];
bool vis[10005];
int lv[10005];
int cand, max_lv;
int ans;
void dfs(int now, int p) {
    lv[now] = (~p ? lv[p] + 1 : 0);
    if (lv[now] > max_lv) {
        max_lv = lv[now];
        cand = now;
    }
    vis[now] = true;
    for (int next : graph[now]) {
        if (!vis[next]) {
            dfs(next, now);
        }
    }
}
void dfs_two(int now, int dis) {
    ans = max(ans, dis);
    vis[now] = true;
    for (auto next : graph[now]) {
        if (!vis[next]) {
            dfs_two(next, dis+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    while (cin >> n) {
        cand = 0, max_lv = 0, ans = 0;
        memset(lv, 0, sizeof(lv));
        for (int i = 0; i < n; ++i) {
            graph[i].clear();
        }
        string tmp;
        getline(cin, tmp);
        for (int i = 0; i < n; ++i) {
            string str; getline(cin, str);
            stringstream ss; 
            ss << str;
            int num;
            while (ss >> num && num != -1) {
                graph[i].push_back(num);
                graph[num].push_back(i);
            }
        }
        memset(vis, 0, sizeof(vis));
        dfs(0, -1);
        memset(vis, 0, sizeof(vis));
        dfs_two(cand, 0);
        cout << ans << endl;
    }
    Time();
    return 0;
}

