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

int arr[200005];
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int sq = (int)sqrt(i);
        int now = i;
        for (int j = sq; j > 1; --j) {
            if (now % (j*j) == 0) {
                now /= j*j;
            }
        }
        debug(i, now);
        arr[now]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        debug(i, arr[i]);
        cnt += arr[i]*arr[i];
    }
    cout << cnt << endl;
    Time();
    return 0;
}

