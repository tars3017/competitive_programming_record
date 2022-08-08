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
    int a, b, c; cin >> a >> b >> c;
    if (a < b) swap(a, b);
    if (b < c) swap(b, c);
    if (a < b) swap(a, b);
    if (a == b && b == c) cout << 3 << ' ' << a << endl;
    else if (a == b && b != c) cout << 2 << ' ' << b << ' ' << c << endl;
    else if (a != b && b == c) cout << 2 << ' ' << a << ' ' << c << endl;
    else cout << 1 << ' ' << a << ' ' << b << ' ' << c << endl;
    return 0;
}

