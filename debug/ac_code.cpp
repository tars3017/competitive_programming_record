#include <bits/stdc++.h>
using namespace std;
#ifdef tars3017
#define debug(...) do {\
    fprintf(stderr, "%d - (%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T>void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#else
#define debug(...)
#endif

int dir[5][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
map< pair<int, int>, int > vis;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    map<char, int> mp;
    mp['N'] = 0;
    mp['S'] = 1;
    mp['E'] = 2;
    mp['W'] = 3;
    while (t--) {
        vis.clear();
        //memset(vis, 0, sizeof(vis));
        int n, r, c, sr, sc; cin >> n >> r >> c >> sr >> sc;
        vis[make_pair(sr, sc)] = 1;
        while (n--) {
            char x; cin >> x;
            sr += dir[mp[x]][0], sc += dir[mp[x]][1];        
            while (vis[make_pair(sr, sc)]) {
                sr += dir[mp[x]][0];
                sc += dir[mp[x]][1];
            }
            vis[make_pair(sr, sc)] = 1;
        }
        cout << "Case #" << Case++ << ": " << sr << ' ' << sc << endl;
    }  
    return 0;
}
