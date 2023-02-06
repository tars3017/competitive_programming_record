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

int arr[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        int appear = 0;
        // 1 (1, -1)  2 (-1, -1)
        for (int i = 1; i < n; ++i) {
            if (appear == 0 && arr[i] * arr[i+1] == -1) {
                appear = 1;
            }
            else if (arr[i] * arr[i+1] == 1 && arr[i] == -1) {
                appear = 2;
            }
        }
        if (appear == 0) {
            sum -= 4;
        }
        else if (appear == 2) {
            sum += 4; 
        }
        cout << sum << endl;
    }
    return 0;
}

