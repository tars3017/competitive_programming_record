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
int total, mx;
int n, p;
int arr[30];
void rec(int now) {
    if (now == n) {
        if (total > mx && total < p) {
            mx = total;
        }
        return ;
    }
    rec(now+1);
    total += arr[now];
    rec(now+1);
    total -= arr[now];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    total = 0, mx = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    rec(0);
    cout << mx << endl;
    return 0;
}

