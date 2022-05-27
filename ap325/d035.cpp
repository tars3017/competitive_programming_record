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
#else 
#define debug(...)
#endif
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
ll n, arr[200005];
ll color[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll ans = 1;
    ll left = 0;
    color[arr[0]]++;
    for (int i = 1; i < n; i++) {
        color[ arr[i] ]++;
        if ( color[ arr[i] ] == 1) {
            ans = max(ans, i-left+1);
        }
        else {
            while (left < i && color[arr[i]] > 1) {
                color[arr[left]]--;
                left++;
            }
        }
        debug(i, left);
    }
    cout << ans << endl;
    return 0;
}

