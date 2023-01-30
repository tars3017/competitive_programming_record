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

int cnt[30];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        int n; cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i]-'a'];
        }
        int used_cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                ++used_cnt;
            }
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l+r) >> 1;
            int out = 0, in = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                if (cnt[i] > mid) {
                    out += cnt[i] - mid;
                }
                else {
                    in += mid - cnt[i];
                }
            }
            debug(in, out, mid, l, r);
            if (out > in) {
                l = mid;
            }
            else if (out == in) {
                r = mid;
            }
            else if (out < in) {
                r = mid;
            }
        }
        cout << r << endl;
    }
    return 0;
}

