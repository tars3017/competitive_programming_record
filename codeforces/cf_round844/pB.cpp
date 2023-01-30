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

int arr[200005];
int cnt[200005];
set<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(cnt, 0, sizeof(cnt));
        s.clear();
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            ++cnt[arr[i]];
            s.insert(arr[i]);
        }
        int now_people = 0, max_req= 0;
        int ans = 0;
        for (auto i = s.begin(); i != s.end(); ++i) {
            debug(*i, now_people, cnt[*i]);
            max_req = *i;
            now_people += cnt[*i];
            ++i;
            if (now_people > max_req  && (i == s.end() || *(i) > now_people) ) {
                ++ans;
            }
            --i;
        }
        if (cnt[0] == 0) ++ans;
        cout << ans << endl;
    }
    return 0;
}

