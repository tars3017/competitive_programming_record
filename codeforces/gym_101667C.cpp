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
vector<int> graph[100005];
pair<int, int> road[300005];
int deg[100005], in_deg[100005];
int dp[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        road[i] = make_pair(a, b);
        deg[a]++, deg[b]++;
    }
    for (int i = 0; i < m; ++i) {
        int a = road[i].F, b = road[i].S;
        if (deg[a] < deg[b]) {
            graph[a].push_back(b);
            in_deg[b]++;
        }
        else if (deg[b] < deg[a]) {
            graph[b].push_back(a);
            in_deg[a]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    int ans = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : graph[now]) {
            dp[next] = max(dp[next], dp[now]+1);
            ans = max(ans, dp[next]);
            in_deg[next]--;
            if (in_deg[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << ans << endl;
    Time();
    return 0;
}

