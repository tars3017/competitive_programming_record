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
    int n; cin >> n;
    char c;
    string str = "codeforces";
    for (int i = 0; i < n; ++i) {
        cin >> c;
        bool appear = 0;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == c) {
                appear = 1;
                break;
            }
        }
        if (appear) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

