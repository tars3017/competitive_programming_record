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
int cnt(int a, int b, int ans) {
    if ((a == 1 && b == 1) || ( a == b)) return ans;
    if (a > b) {
        return cnt(a/2, b, ans+1);
    }
    else {
        return cnt(a, b/2, ans+1);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        cout << cnt(a, b, 0) << endl;
    }
    return 0;
}

