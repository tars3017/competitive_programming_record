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
#else 
#define debug(...)
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
unordered_map<string, int> receptable, device;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        receptable.clear();
        device.clear();
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            receptable[s] = i;  
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string s, plug; cin >> s >> plug;
            if (!receptable.count(plug)) {
                device[plug]++;
            }
        }
        int k; cin >> k;
        // quit at 5/12 
    }
    return 0;
}

