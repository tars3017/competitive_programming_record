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

int arr[50005];
int n, k; 
bool f(int len) {
    int right_bound = arr[0]+len;
    int cnt = 1;
    for (int i = 1; i < n; ) {
        if (right_bound >= arr[i]) {
            i++;
        }
        else {
            cnt++;
            right_bound = arr[i]+len;
            i++;
        }
    }
    if (cnt <= k) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l+r) / 2;
        if (f(mid) == 0) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout << l << endl;
    Time();
    return 0;
}

