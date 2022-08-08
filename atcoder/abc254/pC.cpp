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

vector<priority_queue<int>> v;
vector<priority_queue<int>> v2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    v.resize(k+5);
    v2.resize(k+5);
    int idx = 0;
    for (int i = 0; i < n; ++i) {
        idx = i % k;
        int value; cin >> value;
        v[idx].push(value);
        v2[idx].push(-value);
    }
    int now = 0, past = INT_MAX;
    bool able = true, able2 = true;
    for (int i = 0; i < n; ++i) {
        idx = i % k;
        if (v[idx].empty()) break;
        now = v[idx].top();
        v[idx].pop();
        debug(now, past);
        if (now > past) {
            able = false;
            break;
        }
        past = now;
    }
    now = 0, past = 0;
    for (int i = 0; i < n; ++i) {
        idx = i % k;
        if (v2[idx].empty()) break;
        now = v2[idx].top();
        v2[idx].pop();
        debug(now, past);
        if (now > past) {
            able2 = false;
            break;
        }
        past = now;
    }
    if (able2) cout << "Yes" << endl;
    else cout << "No" << endl;
    Time();
    return 0;
}

