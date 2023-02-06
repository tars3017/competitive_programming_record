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
    int maxn = 0;
    for (int i = 1; i <= 1000000000; ++i) {
        debug(i);
        int now = i;
        int times = 0;
        if (now < 10) continue;
        for (int j = 1; now >= 10 && j <= 5; ++j) {
            times = 0;
            while (now > 0) {
                times += now%10;
                now /= 10;
            }
            now = times;
            times = j;
        }
        maxn = max(maxn, times);
    }
    debug(maxn);
    return 0;
}

