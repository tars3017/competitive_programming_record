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

int arr[10][10];
int ans;
void backtracking(int q[], int cur_col) {
    if (cur_col > 8) {
        /* for (int i = 1; i <= 8; ++i) { */
        /*     cout << "(" << q[i] << "," << i << ") "; */
        /* } */
        /* cout << endl; */
        int now = 0;
        for (int i = 1; i <= 8; ++i) {
            now += arr[q[i]][i];
        }
        ans = max(ans, now);
        return ;
    }
    for (int i = 1; i <= 8; ++i) {
        q[cur_col] = i;
        bool valid = true;
        for (int j = 1; j < cur_col; ++j) {
            if (q[j] == i || ( cur_col + i == j + q[j] ) || ( cur_col - i == j - q[j] ) ) {
                valid = false;
                break;
            }
        }
        if (valid) backtracking(q, cur_col+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k; cin >> k;
    while (k--) {
        memset(arr, 0, sizeof(arr));
        ans = 0;
        for (int i = 1; i <= 8; ++i) {
            for (int j = 1; j <= 8; ++j) {
                cin >> arr[i][j];
            }
        }
        int q[10];
        backtracking(q, 1);
        cout << ans << endl;
    }
    Time();
    return 0;
}

