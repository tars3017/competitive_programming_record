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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1; 
    while (t--) { 
        int r, c; cin >> r >> c; 
        cout << "Case #" << Case++ << ":" << endl;
        cout << "..";
        for (int j = 1; j < c; j++) {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << "..";
        for (int j = 1; j < c; j++) {
            cout << "|."; 
        }
        cout << "|" << endl;
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << "+-";
            }
            cout << "+" << endl;
            for (int j = 0; j < c; j++) {
                cout << "|.";
            }
            cout << "|" << endl;
        }
        for (int j = 0; j < c; j++) {
            cout << "+-";
        }
        cout << "+" << endl;
    }
    return 0;
}
