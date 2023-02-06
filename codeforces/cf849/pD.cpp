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

int cnt1[50], cnt2[50];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        int a = 0, b = 0;
        int n; cin >> n;
        string str; cin >> str;
        a = 1;
        ++cnt1[str[0]-'a'];
        for (int i = 1; i < str.size(); ++i) {
            if (cnt2[str[i]-'a'] == 0) ++b;
            ++cnt2[str[i]-'a'];
        }
        int ans = 0;
        ans = a + b;
        debug(a, b);
        for (int i = 1; i < str.size()-1; ++i) {
            if (cnt1[str[i]-'a'] == 0) ++a;
            cnt1[str[i]-'a']++;

            if (cnt2[str[i]-'a'] == 1) --b;
            cnt2[str[i]-'a']--;
            
            debug(i, a, b);
            ans = max(ans, a+b);
        }
        cout << ans << endl;
    }
    return 0;
}

