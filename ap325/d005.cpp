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
string s; 
int start;
int rec(int side) {
    debug(start, side);
    if (start >= (int)s.size()) return 0;
    else if (side == 1) {
        return (s[start] == '1' ? 1 : 0);
    }
    int ans = 0;
    int cnt = 4;
    while (cnt-- && start < (int)s.size()) {
        if (s[start] == '1') {
            ans += side/2 * side/2;
            start++;
        }
        else if (s[start] == '2') {
            start++;
            ans += rec(side/2);
        }
        else {
            start++;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n; cin >> n;
    start = 0;
    if (s[0] == '2') start++;
    cout << rec(n) << endl;
    return 0;
}

