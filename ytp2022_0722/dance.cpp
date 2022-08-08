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

struct paddle {
    int x, y;
    int idx;
    paddle(int _x, int _y, int _idx) {
        x = _x;
        y = _y;
        idx = _idx;
    }
};
bool bulb[100005];
pii ctl[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> bulb[i];
    }
    deque<int> dq;
    int push_cnt = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> ctl[i].F >> ctl[i].S;
        dq.push_back(i);
    }
    vector<int> ans;
    int light_out_num = 0;
    while (!dq.empty() && push_cnt < m && light_out_num < dq.size()) {
        int now = dq.front();
        debug(now, push_cnt, light_out_num);
        dq.pop_front();
        if (bulb[ctl[now].F] || bulb[ctl[now].S]) {
            ans.push_back(now);
            push_cnt++;
            if (bulb[ctl[now].F] && bulb[ctl[now].S]) {
                light_out_num++;
            }
            bulb[ctl[now].F] ^= 1;
            bulb[ctl[now].S] ^= 1;
        }
        else {
            dq.push_back(now);
            light_out_num++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << bulb[i] << '@';
        }
        cout << endl;
    }
    bool able = true;
    for (int i = 1; i <= n; ++i) {
        if (bulb[i]) {
            able = false;
            break;
        }
    }
    if (able) {
        cout << "Yes" << endl;
        cout << push_cnt << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " \n"[i == ans.size()-1];
        }
    }
    else {
        cout << "No" << endl;
    }
    Time();
    return 0;
}

