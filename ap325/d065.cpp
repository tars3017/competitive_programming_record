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
ll arr[100005] = {};
ll dc(int l, int r) {
    if (l+1 == r) return arr[l];
    if (r <= l) return 0;
    debug(l, r);
    int mid = (l+r) / 2;
    ll ans = max(dc(l, mid), dc(mid+1, r));
    int i = mid, j = mid;
    ll low = min( arr[i], min(arr[j], arr[mid]) );
    while (1) {
        debug(i, j);
        if (i <= l && j >= r) break;
        if (i == l || (j < r-1 && arr[i-1] < arr[j+1]) ) {
            j++;
            low = min(low, arr[j]);
            ans = max(ans, low * (j-i+1) );
        }
        else if (i == l) break;
        else {
            i--;
            low = min(low, arr[i]);
            ans = max(ans, low * (j-i+1) );
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << dc(0, n) << endl;
    return 0;
}

