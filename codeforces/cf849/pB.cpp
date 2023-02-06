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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    string str;
    while (t--) {
        int n; cin >> n;
        cin >> str;
        int x = 0, y = 0;
        bool pass = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'U') {
                ++y;
            }
            else if (str[i] == 'R') {
                ++x;
            }
            else if (str[i] == 'L') {
                --x;
            }
            else if (str[i] == 'D') {
                --y;
            }
            if (x == 1 && y == 1) {
                pass = 1;
                break;
            }
        }
        if (pass) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

