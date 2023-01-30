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

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}
int unsortedness(const string& s) {
    int cnt[5] = {};
    int val = 0;
    for (int i = s.size()-1; i >= 0; --i) {
        int code = 0;
        if (s[i] == 'A') code = 0;
        else if (s[i] == 'C') code = 1;
        else if (s[i] == 'G') code = 2;
        else if (s[i] == 'T') code = 3;
        // debug(code);
        for (int j = 0; j < code; ++j) {
            val += cnt[j];
            // debug(j, cnt[j]);
        }
        ++cnt[code];
    }
    return val;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    debug(unsortedness("CCCGGGGGGA"));
    int t; cin >> t;
    bool first = 1;
    while (t--) { 
        vector< pair<int, string> > v;
        int n, m; cin >> n >> m;
        string str;
        for (int i = 0; i < m; ++i) {
            cin >> str;
            int num = unsortedness(str); 
            v.push_back({num, str});
            debug(num, str);
        }
        stable_sort(v.begin(), v.end(), cmp);
        if (first) first = 0;
        else cout << endl;
        for (int i = 0; i < m; ++i) {
            cout << v[i].second << endl;
        }
    }
    return 0;
}

