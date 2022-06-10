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
int arr[200005], BIT[200005];
void upd(int k, int x) {
    while (k <= n) {
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
int search(int target) {
    int k = 0;
    for (int i = 17; i >= 0; i--) {
        if (k + (1<<i) <= n && BIT[k+(1<<i)] <= target && BIT[k+(1<<i)] && target) {
            debug(1<<i, BIT[k+(1<<i)], target);
            target -= BIT[k+(1<<i)]; 
            k += (1<<i);
        }
    }
    return k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        upd(i, 1);
    }
    // for (int j = 1; j <= n; j++) cout << sum(j) << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        // if (i) cout << ' ';
        // debug(num);
        int idx = search(num);
        // cout << arr[idx];
        // debug(idx);
        upd(idx, -1);
        cout << endl;
        for (int j = 1; j <= n; j++) cout << BIT[j] << ' ';
        cout << endl;
    }
    return 0;
}
