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
ll arr[200005];
unordered_map<int, int> mp;
struct Node {
    ll data, pre_max, suf_max, all_sum;
}ST[200005*4];
void build(int i, int l, int r) {
    if (l == r) {
        mp[l] = i;
        ST[i].data = arr[l];
        ST[i].pre_max = arr[l];
        ST[i].suf_max = arr[l];
        ST[i].all_sum = arr[l];
        return ;
    }
    int lson = i*2+1, rson = i*2+2, m = (l+r) / 2;
    build(lson, l, m);
    build(rson, m+1, r);
    ST[i].data = max(ST[lson].data, ST[rson].data);
    ST[i].data = max(ST[i].data, ST[lson].suf_max+ST[rson].pre_max);

    ST[i].all_sum = ST[lson].all_sum + ST[rson].all_sum;

    ST[i].pre_max = max(ST[lson].pre_max, ST[lson].all_sum+ST[rson].pre_max);
    ST[i].suf_max = max(ST[rson].suf_max, ST[rson].all_sum+ST[lson].suf_max);
}
void upd(int k, ll x) {
    ST[k].data += x;
    ST[k].pre_max += x;
    ST[k].suf_max += x;
    ST[k].all_sum += x;

    k = (k-1) / 2;
    while (k > 0) {
        int lson = k*2+1, rson = k*2+2;
        ST[k].data = max(ST[lson].data, ST[rson].data);
        ST[k].data = max(ST[k].data, ST[lson].suf_max+ST[rson].pre_max);

        ST[k].all_sum = ST[lson].all_sum + ST[rson].all_sum;

        ST[k].pre_max = max(ST[lson].pre_max, ST[lson].all_sum+ST[rson].pre_max);
        ST[k].suf_max = max(ST[rson].suf_max, ST[rson].all_sum+ST[lson].suf_max);
        k = (k-1) / 2;
    }
}
// ll query(int i, int l, int r) {
//     if (l == r) {
//         return ST[i].data;
//     }
//     int m = (l+r) / 2, lson = i*2+1, rson = i*2+2;
//     ll x1 = 
// }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);
    while (m--) {
        ll k, x; cin >> k >> x;
        debug(mp[k]);
        upd(mp[k], x-arr[k]);
        arr[k] = x;
        for (int i = 1; i <= 10; ++i) {
            debug(i, ST[i].data, ST[i].all_sum, ST[i].pre_max, ST[i].suf_max);
        }
        debug(15, ST[15].data, ST[15].all_sum, ST[15].pre_max, ST[15].suf_max);
        debug(16, ST[16].data, ST[16].all_sum, ST[16].pre_max, ST[16].suf_max);
        
        cout << max(ST[1].data, (ll)0) << endl;
        // cout << max(query(1, 1, n), (ll)0) << endl;
    }
    return 0;
}

