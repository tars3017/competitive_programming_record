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

int arr[100005], arr2[100005];
int ST[100005*2];
int n, k; 
void upd(int i, int x) {
    i += n;
    ST[i] = x;
    for (int j = i/2; j > 0; j /= 2) {
        ST[j] = min(ST[j*2], ST[j*2+1]);
    }
}
int qry(int l, int r) {
    l += n, r += n;
    int ans = INT_MAX;
    while (l <= r) {
        if (l%2 == 1) {
            ans = min(ans, ST[l++]);
        }
        if (r%2 == 0) {
            ans = min(ans, ST[r--]);
        }
        l /= 2, r /= 2;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr2));
        memset(ST, 0x3f, sizeof(ST));
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        sort(arr2, arr2+n);
        set<int> s;
        for (int i = 0; i < k; ++i) {
            s.insert(arr2[i]);
            debug("insert", arr2[i]);
        }
        for (int i = 0; i < n && k > 0; ++i) {
            if (s.count(arr[i])) {
                k--;
                s.erase(arr[i]);
                arr[i] = 1e9;
            }
        }
        int min_v = 0x3f3f3f3f;
        for (int i = 0; i < n; ++i) {
            min_v = min(min_v, arr[i]);
        }
        for (int i = 0; i < n; ++i) {
            upd(i, arr[i]);
        }
        for (int i = 1; i <= 2*n; ++i) {
            debug(i, ST[i]);
        }
        int fnl = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int dis = min(min_v*2, qry(i, j));
                fnl = max(fnl, dis);
            }
        }
        cout << fnl << endl;
    }
    Time();
    return 0;
}

