// google kickstart practice #3 wiggle walk
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

long long dir[5][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 
map< pair<long long, long long>, bool > vis;
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
        long long n, r, c, sr, sc; cin >> n >> r >> c >> sr >> sc;
        vis[make_pair(sr, sc)] = 1;
        while (n--) {
            char x; cin >> x;
            debug("from", sr, sc); 
            /* sr += dir[mp[x]][0], sc += dir[mp[x]][1]; */
            /* if(vis[make_pair(sr, sc)]) { */
            for (long long i = 0; i <= 20; ++i) {
                long long nextR = sr + (1<<i) * dir[mp[x]][0];
                long long nextC = sc + (1<<i) * dir[mp[x]][1];
                if (sr == 1 && sc == 5) {
                    debug(1<<i, nextR, nextC);
                }
                if (nextR > 0 && nextR <= r && nextC > 0 && nextC <= c && vis[ make_pair(nextR, nextC) ]) {
                    sr += (1<<i) * dir[mp[x]][0];
                    sc += (1<<i) * dir[mp[x]][1];
                }
            }
            /* } */
            while (vis[make_pair(sr, sc)]) {
                sr += dir[mp[x]][0];
                sc += dir[mp[x]][1];
            }
            debug("to", sr, sc);
            vis[make_pair(sr, sc)] = 1;
        }
        for (auto iter = vis.begin(); iter != vis.end(); iter++) {
            if (iter->second) {
                debug(iter->first.first, iter->first.second);
            }
        }
        cout << "Case #" << Case++ << ": " << sr << ' ' << sc << endl;
    }  
    return 0;
}
