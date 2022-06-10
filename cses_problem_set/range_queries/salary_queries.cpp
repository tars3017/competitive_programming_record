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
#define MAXN 10000000
int n, q;
int arr[10000005];
int arr2[10000005];
int BIT[10000005];
void upd(int k, int x) {
    while (k <= MAXN) {
        BIT[k] += x;
        k += k&-k;
    }
}
int sum(int k) {
    int s = 0;
    while (k > 0) {
        s += BIT[k];
        k -= k&-k;
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int num; cin >> num;
        arr[i] = num;
        // arr2[i] = num;
        mp[num]++;
        upd(num/100 + 1, 1);
    }
    // sort(arr2+1, arr2+1+n);
    while (q--) {
        char opt; cin >> opt;
        if (opt == '!') {
            int k, x; cin >> k >> x;
            upd(arr[k]/100 + 1, -1); 
            upd(x/100 + 1, 1);
            mp[arr[k]]--;
            mp[x]++;
        }
        else {
            int a, b; cin >> a >> b;
            int ans = 0;
            if (a/100 == b/100 || b/100 == a/100 + 1) {
                auto pos1 = mp.lower_bound(a);
                for (auto i = pos1; i != mp.end() && i->F <= b; i++) {
                    ans += i->S;
                }
                cout << ans << endl;
                continue;
            }
            ans = sum(b/100) - sum(a/100+1);
            debug(sum(b/100), sum(a/100+1), ans);
            auto pos1 = mp.lower_bound(a);
            for (auto i = pos1; i != mp.end() && i->F < (a/100)*100+100; i++) {
                ans += i->S;
                debug("left+", i->F, i->S);
            }
            auto pos2 = mp.upper_bound(b/100*100);
            for (auto i = pos2; i != mp.end() && i->F < b; i++) {
                ans += i->S;
                debug("right+", i->F, i->S);
            }
            cout << ans << endl;
        }
    }
    return 0;
}

