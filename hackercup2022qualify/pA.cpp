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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int Case = 1;
    while (t--) {
        int n, k; cin >> n >> k;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            mp[num]++;
        }
        bool able = true;
        int a = 0, b = 0;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            if (iter->S >= 3) {
                able = false;
                break;
            }
            else if (iter->S == 2) {
                a++;
            }
            else {
                b++;
            }
        }
        if (a > k || k*2 < n) able = false;
        cout << "Case #" << Case++ << ": " << (able?"YES":"NO") << endl;
    }
    Time();
    return 0;
}

