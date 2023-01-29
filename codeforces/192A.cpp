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

int main() {
    // 07:15
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long n; cin >> n;
    n *= 2;
    bool able = false;
    for (int i = 1; i <= n; ++i) {
        unsigned long long now = n - ( i * (i+1) );

        if (tmp * (tmp+1) == now) {
            able = true; 
            break;
        }
    }
    cout << (able ? "YES" : "NO") << endl;
    Time();
    return 0;
}

