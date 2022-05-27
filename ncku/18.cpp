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

vector<long long> v;
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t; cin >> t;
    while (t--) {
        long long n, w; cin >> n >> w;
        v.clear();
        v.push_back(1);
        for (int i = 0; i < n; i++) {
            char s;
            long long p; cin >> s >> p;
            if (s == 'b') v.push_back(p);
        }
        v.push_back(w);
        // int ans = w;
        long long ans = 0;
        for (int i = 0; i < v.size()-1; i++) {
           ans = max(ans, v[i+1]-v[i]); 
        }
        if (ans == 0) ans = w;
        cout << ans << endl;
    }
    return 0;
}

