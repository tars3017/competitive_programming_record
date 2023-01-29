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

int r, c; 
char g[105][105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        memset(g, 0, sizeof(g));
        cin >> r >> c;
        int cnt = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> g[i][j];
                if (g[i][j] == '^') cnt++;
            }
        }
        if (cnt > 0 && (r == 1 || c == 1) ) {
            cout << "Case #" << Case++ << ": " << "Impossible" << endl; 
        }
        else if (cnt == 0) {
            cout << "Case #" << Case++ << ": " << "Possible" << endl; 
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << g[i][j];
                }
                cout << endl;
            }
        }
        else {
            cout << "Case #" << Case++ << ": " << "Possible" << endl; 
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cout << '^';
                }
                cout << endl;
            }
        }
    }
    Time();
    return 0;
}

