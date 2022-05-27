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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int arr[105];
    while (t--) {
        memset(arr, 0, sizeof(arr));
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int now;
            cin >> now;
            debug(now);
            arr[now]++;
            // debug(arr[now]);
        }
        sort(arr+1, arr+1+100);
        cout << n-arr[100] << endl;
    }
    return 0;
}

