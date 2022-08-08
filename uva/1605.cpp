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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    char floor[55][55][3];
    char symbol[55];
    for (int i = 0; i < 26; ++i) {
        symbol[i] = 'A'+i;
    }
    for (int i = 26; i <= 50; ++i) {
        symbol[i] = 'a'+(i-26);
    }
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                floor[i][j][0] = symbol[i];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                floor[i][j][1] = symbol[j];
            }
        }
        cout << 2 << ' ' << n << ' ' << n << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << floor[i][j][0];
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << floor[i][j][1];
            }
            cout << endl;
        }
        cout << endl;

    }
    Time();
    return 0;
}

