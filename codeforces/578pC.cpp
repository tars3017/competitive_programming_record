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

double arr[200005];
double pre[200005];
int n;
double f(double x) {
    memset(pre, 0, sizeof(pre));
    double min_pre = min(0.0, arr[0]-x);
    double max_pre = max(0.0, arr[0]-x);
    pre[0] = arr[0]-x;
    double ans = abs(arr[0]-x);
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i-1] + arr[i] - x;
        ans = max(ans, abs(pre[i]-min_pre));
        ans = max(ans, abs(pre[i]-max_pre));
        /* debug(i, pre[i], min_pre, max_pre); */
        min_pre = min(min_pre, pre[i]);
        max_pre = max(max_pre, pre[i]);
    }
    return ans;
}
int main() {
    /* ios_base::sync_with_stdio(false); */
    /* cin.tie(0); */
    double v[20] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    double now = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            double tmp = 0;
            for (int k = j; k <= i; ++k) {
                tmp += v[i]-5.756;
            }
            now = max(now, abs(tmp));
        }
    }
    debug(now);
    cin >> n;
    double l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        r = max(r, arr[i]);
    }
    /* double x = f(4.5); */
    /* debug(x); */
    while (r-l > 0.000000001) {
        double ml = l + (r-l) / 3;
        double mr = l + (r-l) * 2 / 3;
        debug(l, ml, mr, r, f(ml), f(mr));
        if (f(ml) > f(mr)) {
            l = ml;
        }
        else {
            r = mr;
        }
    }
    cout << f(l) << endl;
    debug(f(5.756));
    Time();
    return 0;
}

