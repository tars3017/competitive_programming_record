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
ll backward[200005], foreward[200005];
struct Node {
    ll chg, data;
    Node(): chg(0), data(LLONG_MAX) {}
};
struct segment_tree {
    // int arr[200005];
    // Node ST[200005*4];
    vector<int> arr;
    vector<ll> ST;
    void init(int n) {
        arr.resize(n+1);
        ST.resize(2*n+5, LLONG_MAX); 
    }
    void upd(int k, int x) {
        k += n;
        if (ST[k] == LLONG_MAX) ST[k] = 0;
        ST[k] += x;
        for (k /= 2; k > 0; k /= 2) {
            ST[k] = min(ST[k*2], ST[k*2+1]);
        }
    }
    ll query(int a, int b) {
        if (a <= 0 || b <= 0) return LLONG_MAX;
        a += n, b += n;
        ll s = LLONG_MAX;
        while (a <= b) {
            if (a % 2 == 1) {
                s = min(s, ST[a++]);
            }
            if (b % 2 == 0) {
                s = min(s, ST[b--]);
            }
            a /= 2, b /= 2;
        }
        return s;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    segment_tree foreward;
    foreward.init(n);
    segment_tree backward;
    backward.init(n);

    for (int i = 1; i <= n; i++) {
        int now; cin >> now;
        // foreward.arr[i] = now+i;
        // backward.arr[i] = now-i;
        foreward.arr[i] = now+i;
        backward.arr[i] = now-i;
        foreward.upd(i, now+i);
        backward.upd(i, now-i);
    }
    // foreward.build(1, 1, n);
    // backward.build(1, 1, n);
    
    // debug(backward.query(1, 3, 1, 4, 6));
    while (q--) {
        for (int i = 1; i <= n; i++) {
            debug(foreward.query(i, i), backward.query(i, i));
        }
        int opt; cin >> opt;
        if (opt == 1) {
            ll k, x; cin >> k >> x;
            foreward.upd(k, x+k-foreward.arr[k]);
            foreward.arr[k] = x+k;
            debug(x, k, foreward.arr[k]);

            backward.upd(k, x-k-backward.arr[k]);
            backward.arr[k] = x-k;
        }
        else {
            int k; cin >> k;
            ll ans1 = foreward.query(k, n) - k;
            ll ans2 = backward.query(1, k) + k;
            cout << min(ans1, ans2) << endl;
        }
    }
    return 0;
}

