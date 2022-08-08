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

ll arr[5005];
ll d[5005][5005][3];
int n; 
ll dp(int l, int r, bool my_turn) {
    if (l > r || r > n) return 0;
    if (d[l][r][my_turn]) return d[l][r][my_turn];
    debug(l, r, my_turn);
    if (my_turn) {
        return d[l][r][my_turn] = max(dp(l, r-1, !my_turn)+arr[r], dp(l+1, r, !my_turn)+arr[l]);
    }
    else {
        return d[l][r][my_turn] = min(dp(l, r-1, !my_turn), dp(l+1, r, !my_turn));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    cout << dp(1, n, 1) << endl;
    return 0;
}

