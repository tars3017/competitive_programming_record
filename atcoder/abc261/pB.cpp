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

char arr[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
        if (!valid) break;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            debug(arr[i][j], arr[j][i]);
            if ( (arr[i][j] == 'W' && arr[j][i] != 'L') || (arr[i][j] == 'L' && arr[j][i] != 'W') || 
                 (arr[i][j] == 'D' && arr[j][i] != 'D') ) {
                valid = false;
                break;
            }
        }
    }
    cout << (valid ? "correct" : "incorrect") << endl;
    Time();
    return 0;
}

