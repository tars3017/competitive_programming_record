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

ll arr[100005];
int n, d; 

int dc(int l, int r) {
    if (l+1 == r) {
        return (arr[l] >= d ? 1 : n+10);
    }
    else if (l > r) return 0;
    int mid = l + (r-l)/2;
    int l_ans = dc(l, mid), r_ans = dc(mid, r);
    int ans = n+10;
    ans = min(ans, l_ans);
    ans = min(ans, r_ans);
    vector<pii> suf;
    ll tmp = 0;
    for (int i = mid-1; i >= l; --i) {
        tmp += arr[i];
        suf.push_back({tmp, i});
    }
    sort(suf.begin(), suf.end(), cmp);
    
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> d;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << dc(0, n) << endl;
    }
    Time();
    return 0;
}

