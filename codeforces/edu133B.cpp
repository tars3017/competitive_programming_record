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

vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << n << endl;
        v.clear();
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        for (int i = n-1; i > 0; --i) {
            for (int j = 0; j < n; ++j) {
                cout << v[j] << ' ';
            }
            cout << endl;
            swap(v[i], v[i-1]);
        }
        for (int j = 0; j < n; ++j) {
            cout << v[j] << ' ';
        }
        cout << endl;
    }
    Time();
    return 0;
}

