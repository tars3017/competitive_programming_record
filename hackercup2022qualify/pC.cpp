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

int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        cin >> n;
        string tmp; cin >> tmp;
        string base; 
        if (tmp[0] == '.') {
            base.push_back('-');
            base.push_back('.');
        }
        else {
            base.push_back('.');
            base.push_back('-');
        }
        debug(base);
        cout << "Case #" << Case++ << ":" << endl;
        for (int i = 1; i < n; ++i) {
            cout << base << endl;
            if (base.back() == '.') {
                base.back() = '-';
                base.push_back('.');
            }
            else {
                base.back() = '.';
                base.push_back('-');
            }
        }
    }
    Time();
    return 0;
}

