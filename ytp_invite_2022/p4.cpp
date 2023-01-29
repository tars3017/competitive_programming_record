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

const int MAXN = 1e8 + 5;
int arr[MAXN];
ll ans, total;
int d, y; 
void solve(const int &x, const int &cnt) {
    if (cnt > 4 || total > y) return ;
    if (x == d) {
        if (cnt == 4 && total == y) {
            ans++;
        }
        return ;
    }
    solve(x+1, cnt);
    total += arr[x];
    solve(x+1, cnt+1);
    total -= arr[x];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> d >> y;
    for (int i = 0; i < d; ++i) {
        cin >> arr[i];
    }
    ans = 0;
    total = 0;
    solve(0, 0);
    cout << ans << endl;
    Time();
    return 0;
}

