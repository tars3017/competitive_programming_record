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

int arr[105][105];
bool row[105], col[105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        memset(arr, 0, sizeof(arr));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        int row_t = 0, col_t = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            int now = 0;
            for (int j = 0; j < n; ++j) {
                now += arr[i][j];
            }
            if (now % 2) {
                row[i] = true;
                row_t++;
            }
        }
        for (int j = 0; j < n; ++j) {
            int now = 0;
            for (int i = 0; i < n; ++i) {
                now += arr[i][j];
            }
            if (now % 2) {
                col[j] = true;
                col_t++;
            }
        }
        if (row_t > 1 || col_t > 1 || (row_t == 1 && col_t == 0) || (col_t == 1 && row_t == 0)) {
            cout << "Corrupt" << endl;
        }
        else if (row_t == 0 && col_t == 0) {
            cout << "OK" << endl;
        }
        else {
            int row_mod = 0, col_mod = 0;
            for (int i = 0; i < n; ++i) {
                if (row[i]) {
                    row_mod = i;
                }
                if (col[i]) {
                    col_mod = i;
                }
            }
            cout << "Change bit (" << row_mod+1 << "," << col_mod+1 << ")" << endl;
        }
    }
    Time();
    return 0;
}

