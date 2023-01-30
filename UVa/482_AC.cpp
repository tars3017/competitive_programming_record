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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    string str;
    getline(cin, str);
    bool first = 1;
    while (t--) {
        getline(cin, str);
        debug(str);
        getline(cin, str);
        debug(str);
        stringstream ss;
        ss << str;
        vector< pair<int, string> > a;
        int x;
        while (ss >> x) {
            debug(x);
            a.push_back({x, "a"});
        }
        getline(cin, str);
        bool last_is_char = 0;
        int last_idx = 0;
        x = 0;
        for (int i = 0; i < str.size(); ++i) {
            debug(i, str[i], last_is_char, last_idx, x);
            if ( last_is_char && (str[i] == ' ' || str[i] == '\n') ) {
                debug("here");
                last_is_char = 0;
                a[x].second = str.substr(last_idx, i-last_idx);
                debug(str.substr(last_idx, i-last_idx));
                ++x;
            }
            else if (!last_is_char && str[i] != ' ' && str[i] != '\n') {
                last_idx = i;
                last_is_char = 1;
            }
            else if (str[i] != ' ' && str[i] != '\n') {
                last_is_char = 1;
            }
        }
        if (x < a.size()) {
            a[x].second = str.substr(last_idx, str.size()-last_idx);
        }
        sort(a.begin(), a.end(), cmp);
        if (first) first = 0;
        else cout << endl;
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i].second << endl;
        }
        // cout << endl;
    }
    return 0;
}

