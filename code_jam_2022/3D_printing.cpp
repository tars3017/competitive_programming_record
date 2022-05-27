#include <bits/stdc++.h>
using namespace std;
#ifdef pclh3017
#define debug(...) do {\
    fprintf(stderr, "Line: %d -(%s) = ", __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I, typename...T> void _DO(I&&x, T&&...tail) {
    cerr<<x<<", ";
    _DO(tail...);
}
#else
#define debug(...)
#endif
#define total 1000000
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        int c1, m1, y1, k1; cin >> c1 >> m1 >> y1 >> k1;
        int c2, m2, y2, k2; cin >> c2 >> m2 >> y2 >> k2;
        int c3, m3, y3, k3; cin >> c3 >> m3 >> y3 >> k3;
        int c_max, m_max, y_max, k_max;
        c_max = min( min(c1, c2), c3);
        m_max = min( min(m1, m2), m3);
        y_max = min( min(y1, y2), y3);
        k_max = min( min(k1, k2), k3);
        long long now = 0;
        int arr[5] = {};
        if (now < total && now + c_max > total) {
            arr[0] = total - now;
            now += arr[0];
        }
        else if (now < total) {
            arr[0] = c_max;
            now += arr[0];
        }
        if (now < total && now + m_max > total) {
            arr[1] = total - now;
            now += arr[1];
        }
        else if (now < total) {
            arr[1] = m_max;
            now += arr[1];
        }
        if (now < total && now + y_max > total) {
            arr[2] = total - now;
            now += arr[2];
        }
        else if (now < total) {
            arr[2] = y_max;
            now += arr[2];
        }
        if (now < total && now + k_max > total) {
            arr[3] = total - now;
            now += arr[3];
        }
        else if (now < total) {
            arr[3] = k_max;
            now += arr[3];
        }
        cout << "Case #" << Case++ << ": ";
        if (now == total) {
            cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
