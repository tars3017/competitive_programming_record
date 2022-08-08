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

int arr[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t; 
    while (t--) {
        memset(arr, 0, sizeof(arr));
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int now;
            cin >> now;
            ans = max(ans, now);
        }
        cout << ans << endl;
    }
    Time();
    return 0;
}

