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

struct dot {
    double x, y;
    dot(int _x=0, int _y=0) {
        x = _x;
        y = _y;
    }
};
dot arr[3000005];
bool cmp_y(dot a, dot b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}
int n; 
double closest_pair(int l, int r) {
    if (l >= r) return DBL_MAX;
    if (r == l+1) {
        double x_dif = arr[l].x - arr[r].x;
        double y_dif = arr[l].y - arr[r].y;
        return sqrt(x_dif*x_dif + y_dif*y_dif);
    }
    int mid = (l+r) / 2;
    double l_dis = closest_pair(l, mid);
    double r_dis = closest_pair(mid+1, r);
    double d = min(l_dis, r_dis);
    int l_bound = mid, r_bound = mid;
    while (l_bound >= 1 && arr[mid].x - arr[l_bound].x <= d) {
        l_bound--;
    }
    
    vector<dot> v;
    debug(mid, arr[mid].x, arr[mid].y);
    for (int i = l; i <= r; ++i) {
        if (abs(arr[i].x-arr[mid].x) <= d) {
            v.push_back(arr[i]);
            debug("v", arr[i].x, arr[i].y);
        }
    }
    sort(v.begin(), v.end(), cmp_y);
    /* for (int i = 0; i < v.size(); ++i) { */
    /*     debug(i, v[i].x, v[i].y); */
    /* } */
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i+1; j < v.size() && v[j].y-v[i].y <= d; ++j) {
            double x_dif = v[j].x - v[i].x;
            double y_dif = v[j].y - v[i].y;
            debug(v[i].x, v[i].y, v[j].x, v[j].y);
            d = min(d, sqrt(x_dif*x_dif + y_dif*y_dif));
        }
    }
    return d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].x >> arr[i].y;
    }
    cout << fixed << setprecision(4) << closest_pair(1, n) << endl;
    Time();
    return 0;
}

