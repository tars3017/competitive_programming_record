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

set<string> s;
int cnt;
vector<string> v;
int n; 
void dfs(string cur) {
    if (cnt >= n-1) return ;
    if (cur.size() == 10) {
        v.push_back(cur);
        cnt++;
        return ;
    }
    cur.push_back('.');
    dfs(cur);
    cur.back() = '-';
    dfs(cur);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        v.clear();
        cin >> n;
        s.clear();
        string tmp; cin >> tmp;
        string now;
        now.push_back('.');
        if (tmp[0] == '.') now.back() = '-';
        cnt = 0;
        dfs(now);
        cout << "Case #" << Case++ << ":" << endl;
        for (auto i : v) {
            cout << i << endl;
        }
    }
    Time();
    return 0;
}
