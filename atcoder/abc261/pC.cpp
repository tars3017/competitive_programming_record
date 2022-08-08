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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        int cnt = mp[str];
        if (cnt) {
            cout << str << "(" << cnt << ")" << endl;
        }
        else {
            cout << str << endl;
        }
        mp[str]++;
    }
    Time();
    return 0;
}
