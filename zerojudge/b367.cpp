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

int arr[150];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n*m; ++i) {
            cin >> arr[i];
        }
        bool same = true;
        for (int i = 0; i < n*m; ++i) {
            if (arr[i] != arr[n*m-i-1]) {
                same = false;
                break;
            }
        }
        if (same) {
            cout << "go forward" << endl;
        }
        else {
            cout << "keep defending" << endl;
        }
    }
    
    Time();
    return 0;
}

