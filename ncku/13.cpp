#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#ifdef pclh3017
#define debug(...) do {\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T> void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#else
#define debug(...)
#endif
#define total 1000000

pair<int, int> alc[200005] = {};
int mx[20005][20005];
// pair<int, int> alc2[200005] = {};
pair<int, int> jdg[200005] = {};
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.F != b.F)
        return a.F < b.F;
    else 
        return a.S < b.S;
}
// bool cmp2(pair<int, int> a, pair<int, int> b) {
//     if (a.S != b.S)
//         return a.S < b.S;
//     else 
//         return a.F < b.F;
// }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> alc[i].F >> alc[i].S;
//         alc2[i].F = alc[i].F;
//         alc2[i].S = alc[i].S;
    }
    for (int i = 1; i <= q; i++) {
        cin >> jdg[i].F >> jdg[i].S;
    }
//     sort(alc+1, alc+1+n, cmp);
//     sort(alc2+1, alc2+1+n, cmp2);
    for (int i = 1; i <= n; i++) {
        mx[i][i] = alc[i].S;
        for (int j = i+1; j <= n; j++) {
            mx[i][j] = max(mx[i][j-1], alc[j].S); 
        }
    }
    return 0;
}
