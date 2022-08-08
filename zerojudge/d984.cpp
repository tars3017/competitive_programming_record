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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    pair<ll, ll> arr[5];
    while (cin >> arr[0].F >> arr[1].F >> arr[2].F) {
        arr[0].S = 1, arr[1].S = 2, arr[2].S = 3;
        sort(arr, arr+3);
        debug(arr[0].F, arr[1].F, arr[2].F);
        arr[1].F += arr[0].F;
        if (arr[2].F > arr[1].F) {
            cout << char(arr[2].S+'A'-1) << endl;
        }
        else {
            cout << char(arr[1].S+'A'-1) << endl;
        }
    }
    Time();
    return 0;
}

