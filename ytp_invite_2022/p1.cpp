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

int cnt[15];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    cin >> str;
    vector<int> v;
    ll total = 0;
    for (int i = 0; i < str.size(); i+=2) {
        int now = str[i]-'0';
        v.push_back(now);
        for (int j = 2; j <= now; ++j) {
            cnt[j]++;
        }
        total += now;
    }
    debug(total);
    ll ans = 1;
    for (ll i = 2; i <= total; ++i) {
        ans *= i;
        debug("*", i, ans);
        for (int j = 2; j < 10; ++j) {
            if (cnt[j] > 0 && ans%j == 0) {
                debug("/", j);
                ans /= j;
                cnt[j]--;
            }
        }
    }
    cout << ans << endl;
    Time();
    return 0;
}

