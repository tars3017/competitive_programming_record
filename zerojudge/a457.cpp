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

ll arr1[100005], arr2[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, m; cin >> k >> m;
    for (int i = 1; i <= k; ++i) {
        cin >> arr1[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> arr2[i];
    }
    ll cnt = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = i+1; j <= k; ++j) {
            bool a = (arr1[i] > arr1[j]);
            bool b = (arr2[i] > arr2[j]);
            if (arr1[i] == arr1[j] || arr2[i] == arr2[j]) continue;
            if (a ^ b) {
                cnt++;
                debug(i, j);
            }
        }
    }
    cout << cnt << endl;
    Time();
    return 0;
}

