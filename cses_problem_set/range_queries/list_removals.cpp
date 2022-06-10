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

int n;
pii ST[1<<18];
int sz;
void upd(int k, int x) {
    k += sz;
    ST[k].F = x;
    for (k /= 2; k > 0; k /= 2) {
        ST[k].F = max(ST[k*2].F, ST[k*2+1].F);
    }
}
void remove(int a) {
    upd(a, -1);
    a = a+1+sz;
    int b = n-1 + sz;
    while (a <= b) {
        if (a % 2 == 1) ST[a++].F -= 1;
        if (b % 2 == 0) ST[b--].F -= 1;
        a /= 2, b /= 2;
    }
}
int qry(int a, int b) {
    a += sz, b += sz;
    int s = -1;
    while ( a <= b ) {
        if ( a % 2 == 1 ) s = max(s, ST[a++].F);
        if ( b % 2 == 0 ) s = max(s, ST[b--].F);
        a /= 2, b /= 2;
    }
    return s;
}
int BS(int a, int b, const int &target) {
    int mid = (a+b) / 2;
    if (mid == a && ST[a+sz].F == target) return ST[a+sz].S;
    int l_idx = qry(a, mid);
    debug(a, mid, mid+1, b);
    // debug(l_idx);
    if ( l_idx >= target) {
        return BS(a, mid, target);
    }
    int r_idx = qry(mid+1, b);
    // debug(r_idx);
    if ( r_idx >= target) {
        return BS(mid+1, b, target);
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int power = (int)(ceil(log2(n)));
    sz = 1<<power;
    // debug(sz);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        ST[i+sz].S = num;
        upd(i, i);
    }
    // for (int j = 0; j < 2*sz-1; j++) debug(j+1, ST[j+1].F, ST[j+1].S); 
    for (int i = 0; i < n; i++) {
        int idx; cin >> idx;
        if (i) cout << ' ';
        cout << BS(0, n-1, idx-1); // Binary Search
        remove(idx-1);
        for (int j = 0; j < 2*sz-1; j++) debug(j+1, ST[j+1].F, ST[j+1].S); 
    }
    cout << endl;
    return 0;
}

