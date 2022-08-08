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

bool dir[105][15][15];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w, h; cin >> w >> h;
    char ch;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < 2*w-1; ++j) {
            cin >> ch; 
            if (ch == '-') {
                dir[i][j/2][j/2 + 1] = 1;
                dir[i][j/2 + 1][j/2] = 1;
                debug(i, j/2, j/2 + 1);
            }
        }
    }
    int col;
    int ans[15];
    for (int j = 0; j < w; ++j) {
        col = j;
        for (int i = 0; i < h; ++i) {
            if (col > 0 && dir[i][col][col-1]) {
                debug("one");
                col = col-1;
            }
            else if (col < w-1 && dir[i][col][col+1]) {
                debug("two");
                col = col+1;
            }
        }
        ans[j] = col;
    }
    for (int j = 0; j < w; ++j) {
        cout << ans[j]+1 << ' ';
    }
    cout << endl;
    Time();
    return 0;
}

