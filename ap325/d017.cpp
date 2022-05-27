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
ll n, p;
ll Pow(ll bot, ll exp) {
    if (exp == 1) return bot % p;
    else if (exp % 2) return (Pow(bot, exp-1)*bot) % p;
    else return (Pow(bot, exp/2) * Pow(bot, exp/2)) % p;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    int arr[15] = {};
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        ll now = Pow(arr[i], p-2) % p;
        cout << now << " \n"[i==n-1];
    }
    return 0;
}

