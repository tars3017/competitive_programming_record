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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        string s; cin >> s;
        string ret;
        for (int i = 0; i < s.size()-1; i++) {
            if ( (ret.size() < s.size()-1 && s[i] <= s[ret.size()] && s[i] < s[ret.size()+1]) || (ret.size() == s.size()-1 && s[i] < s[ret.size()]) ) {
                ret.push_back(s[i]);
                ret.push_back(s[i]);
            }
            else {
                ret.push_back(s[i]);
            }
        }
        ret.push_back(s.back());
        cout << "Case #" << Case++ << ": " << ret << endl;
    }
    return 0;
}

