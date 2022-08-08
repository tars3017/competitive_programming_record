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

int f(int x) {
    if (x == 91) return 91;
    else if (x <= 100) return f(f(x+11));
    return x-10;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    while (cin >> n && n) {
        cout << "f91(" << n << ") = " << f(n) << endl;
    }
    Time();
    return 0;
}

