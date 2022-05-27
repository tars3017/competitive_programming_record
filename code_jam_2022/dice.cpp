#include <bits/stdc++.h>
using namespace std;
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        debug(t);
        int n; cin >> n;
        int arr[20] = {};
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sort(arr+1, arr+n+1);
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= arr[i]; j++) {
                int now = 1, start = j+1;
                for (int k = i+1; k <= n; k++) {
                    if (arr[k] >= start) {
                        now++;
                        start++;
                    }
                    else {
                        break;
                    }
                }
                ans = max(ans, now);
            }
        }
        cout << "Case #" << Case++ << ": " << ans << endl;
    }
    return 0;
}
