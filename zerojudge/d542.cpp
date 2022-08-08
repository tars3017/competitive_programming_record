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
int BIT[500005];
int n; 
void upd(int k, int x) {
    for (int i = k; i <= n; i += i&-i) {
        BIT[i] += x;
    }
}
int qry(int k) {
    int now = 0;
    for (int i = k; i > 0; i -= i&-i) {
        now += BIT[i];
    }
    return now;
}
vector<int> v;
vector<int> pos[500005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n && n) {
        memset(BIT, 0, sizeof(BIT));
        v.clear();
        for (int i = 0; i <= n; ++i) pos[i].clear();
        map<int, int> mp;
        v.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int num; cin >> num;
            v.push_back(num);
            mp[num] = 0;
        }
        int idx = 1;
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            debug(iter->F);
            iter->S = idx++;
        }
        idx--;
        for (int i = 1; i <= n; ++i) {
            v[i] = mp[v[i]];
            debug(i, v[i]);
            pos[v[i]].push_back(i);
        }
        ll ans = 0;
        for (int i = idx; i >= 1; --i) {
            for (int j : pos[i]) {
                ans += qry(j-1);
            }
            for (int j : pos[i]) {
                upd(j, 1);
            }
        }
        cout << ans << endl;
    }
    Time();
    return 0;
}

