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
    int t;
    cin >> t;
    while (t--) {
        int w, d, h;
        cin >> w >> d >> h;
        int a, b, f, g; 
        cin >> a >> b >> f >> g;
        int ans = 0x3f3f3f3f;
        int tmp = h, tmp_f = f, tmp_g = g;
        tmp += f;
        tmp_f = 0;
        tmp += abs(tmp_f-a) + abs(tmp_g-b);
        ans = min(ans, tmp); 

        tmp = h;
        tmp_f = f, tmp_g = g;
        tmp += g;
        tmp_g = 0;
        tmp += abs(tmp_f-a) + abs(tmp_g-b);
        ans = min(ans, tmp); 

        tmp = h;
        tmp_f = f, tmp_g = g;
        tmp += w-f;
        tmp_f = w;
        tmp += abs(tmp_f-a) + abs(tmp_g-b);
        ans = min(ans, tmp); 

        tmp = h;
        tmp_f = f, tmp_g = g;
        tmp += d-g;
        tmp_g = d;
        tmp += abs(tmp_f-a) + abs(tmp_g-b);
        ans = min(ans, tmp); 

        cout << ans << endl;
    }
    return 0;
}

