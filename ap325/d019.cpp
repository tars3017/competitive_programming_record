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
ll arr[40] = {};
vector<ll> a, b;
ll sum;
void complete_search(int now, int end, bool opt) {
    if (now == end) {
        if (!opt) a.push_back(sum);
        else b.push_back(sum);
        return ;
    }
    complete_search(now+1, end, opt);
    sum += arr[now];
    complete_search(now+1, end, opt);
    sum -= arr[now];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, p; cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sum = 0;
    complete_search(0, n/2, 0);
    sum = 0;
    complete_search(n/2, n, 1);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    int pos = lower_bound(a.begin(), a.end(), p) - a.begin();
    if (pos && a[pos] > p) pos--;
    ans = a[pos];
    int pos2 = lower_bound(b.begin(), b.end(), p) - b.begin();
    if (pos2 && b[pos2] > p) pos2--;
    ans = max(ans, b[pos2]);

    int l = 0, r = b.size()-1;
    while (l < a.size() && r >= 0) {
        if (a[l] + b[r] <= p) {
            ans = max(ans, a[l] + b[r]);
            l++;
        }
        else {
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}

