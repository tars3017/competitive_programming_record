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

ll fol[100005], ufl[100005];
ll arr[100005];
int main() {
    // https://codeforces.com/problemset/problem/1709/B
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 2; i <= n; ++i) {
        if (arr[i] < arr[i-1]) {
            fol[i] = fol[i-1] + (arr[i-1]-arr[i]);
        }
        else 
            fol[i] = fol[i-1];
    }
    for (int i = n-1; i >= 1; --i) {
        if (arr[i] < arr[i+1]) {
            ufl[i] = ufl[i+1] + (arr[i+1]-arr[i]);
        }
        else 
            ufl[i] = ufl[i+1];
        debug(i, ufl[i]);
    }
    while (m--) {
        int a, b; cin >> a >> b;
        if (a < b) {
            cout << fol[b]-fol[a] << endl; 
        }
        else {
            debug(a, b, ufl[a], ufl[b+1]);
            cout << ufl[b]-ufl[a] << endl;
        }
    }
    Time();
    return 0;
}

