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

int arr[30];
int n;
int ans;
string s;
void rec(ll now, ll num) {
    debug(now, num);
    if (now >= n) {
        if (num % 10009 == 1) {
            ans++;
            debug(s);
        }
        return ;
    }
    s.push_back('0');
    rec(now+1, num);
    s.back() = '1';
    rec(now+1, (!num ? arr[now] : arr[now] * num) % 10009 );
    s.pop_back();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rec(0, 0);
    cout << ans << endl;
    return 0;
}

