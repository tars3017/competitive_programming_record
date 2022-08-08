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

int game(int x, int y, bool is_whey) {
    if ( (x==1 && y == 0) || (x == 0 && y == 1) ) {
        if (is_whey) {
            return 1;
        }
        else {
            return -1;
        }
    }
    int a = 0, b = 0, c = 0, d = 0;
    if (x > 0) {
        a = game(x-1, y, !is_whey);
    }
    if (y > 0) {
        b = game(x, y-1, !is_whey);
    }
    if ( x*y && x > y) {
        c = game(x-y, y, !is_whey);
    }
    if ( x*y && y > x) {
        d = game(x, y-x, !is_whey);
    }
    if (is_whey) {
        int mx = max( max(a, b), max(c, d) );
        if (a == mx) {
            return a;
        }
        else if (b == mx) {
            return b;
        }
        else if (c == mx) {
            return c;
        }
        else if (d == mx) {
            return d;
        }
    }
    else {
        int mn = min( min(a, b), min(c, d) );
        if (a == mn) {
            return a;
        }
        else if (b == mn) {
            return b;
        }
        else if (c == mn) {
            return c;
        }
        else if (d == mn) {
            return d;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (game(a, b, 1) > 0) {
            cout << ">//<" << endl;
        }
        else {
            cout << ">\\\\<" << endl;
        }
    }
    Time();
    return 0;
}

