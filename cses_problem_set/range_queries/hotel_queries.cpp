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

int n, m;
int ST[200005*2];
void upd(int k, int x) {
    k += n;
    ST[k] += x;
    for (k /= 2; k > 0; k /= 2) {
        ST[k] = max(ST[k*2], ST[k*2+1]);
    }
}
int qry(int a, int b) {
    a += n, b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s = max(s, ST[a++]);
        if (b % 2 == 0) s = max(s, ST[b--]);
        a /= 2, b /= 2;
    }
    return s;
}
int BS(int l, int r, const int &target) {
    if (l == r && ST[l+n] >= target) {
        upd(l, -target);
        return l;
    }
    else if (l > r) return 0;
    int mid = (l+r) / 2;
    int l_max = qry(l, mid);
    debug(l, mid, l_max, target);
    if (l_max >= target) {
        return BS(l, mid, target);
    }
    int r_max = qry(mid+1, r);
    debug(mid+1, r, r_max, target);
    if (r_max >= target) {
        return BS(mid+1, r, target);
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        upd(i, num);
    }
    for (int i = 0; i < m; i++) {
        if (i) cout << ' ';
        int people; cin >> people;
        cout << BS(0, n-1, people)+1;
        // for (int j = 0; j < n; j++) {
        //     cout << ST[n+j] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}

