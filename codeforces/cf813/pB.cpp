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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        v.clear();
        for (int i = 1; i <= n; ++i) {
            v.push_back(i);
        }
        if (n % 2) {
            for (int i = 1; i+1 < n; i += 2) {
                swap(v[i], v[i+1]); 
            }
        }
        else {
            for (int i = 0; i+1 < n; i += 2) {
                swap(v[i], v[i+1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    Time();
    return 0;
}

