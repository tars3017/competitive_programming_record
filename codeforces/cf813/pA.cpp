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

int arr[105], arr2[105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(arr2, 0, sizeof(arr2));
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        if (n == k) {
            cout << 0 << endl;
            continue;
        }
        sort(arr2, arr2+n);
        unordered_map<int, int> mp;
        for (int i = 0; i < k; ++i) {
            mp[arr2[i]]++;
        }
        unordered_map<int, int> now;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            now[arr[i]]++;
            if (now[arr[i]] > mp[arr[i]]) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    Time();
    return 0;
}

