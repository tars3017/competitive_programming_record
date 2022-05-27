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
#else 
#define debug(...)
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long

int n, q;
int ST[200005*2];
void upd(int k, int x) {
    k += n;
    ST[k] = x;
    for (k /= 2; k > 0; k /= 2) {
        ST[k] = ST[k*2] ^ ST[k*2+1];
    }
}
int qry(int a, int b) {
    a += n, b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s ^= ST[a++];
        if (b % 2 == 0) s ^= ST[b--];
        a /= 2, b /= 2;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        upd(i, num);
    }
    while (q--) {
        int a, b; cin >> a >> b;
        cout << qry(--a, --b) << endl;
    }
    return 0;
}

