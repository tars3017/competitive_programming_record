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

bool graph[30][30];
int in_deg[30];
vector<string> arr;
int main() {
    // 16min
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (cin >> str) {
        memset(graph, 0, sizeof(graph));
        arr.clear();
        arr.push_back(str);
        while (cin >> str && str != "#") {
            arr.push_back(str);
        }
        memset(in_deg, -1, sizeof(in_deg));
        in_deg[ arr[0][0]-'A' ] = 0;
        for (int i = 1; i < arr.size(); ++i) {
            int idx = 0;
            while (idx < arr[i-1].size() && idx < arr[i].size() && arr[i-1][idx] == arr[i][idx]) {
                idx++;
            }
            if (idx < min(arr[i-1].size(), arr[i].size())) {
                if (in_deg[ arr[i-1][idx] - 'A' ] == -1) {
                    in_deg[ arr[i-1][idx] - 'A' ] = 0; 
                }
                if (in_deg[arr[i][idx]-'A'] == -1) {
                    in_deg[ arr[i][idx] - 'A' ] = 0;
                }
                if (!graph[ arr[i-1][idx]-'A'][arr[i][idx]-'A']) 
                    in_deg[ arr[i][idx] - 'A' ]++;
                graph[ arr[i-1][idx]-'A' ][ arr[i][idx]-'A' ] = 1;
                /* debug("plus", arr[i-1][idx]-'A', in_deg[ arr[i-1][idx]-'A']); */
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; ++i) {
            debug(in_deg[i]);
            if (!in_deg[i]) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int now = q.front();
            debug((char)(now+'A'));
            q.pop();
            ans.push_back(now);
            for (int i = 0; i < 26; ++i) {
                if (graph[now][i]) {
                    debug(i, in_deg[i]);
                    in_deg[i]--;
                    if (in_deg[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        for (int i : ans) {
            cout << (char)(i+'A');
        }
        cout << endl;
    }
    Time();
    return 0;
}

