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

int a[100005], b[100005];
int pa[100005], pb[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x, y; cin >> x >> y;
    for (int i = 1; i <= x; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= y; i++) {
        cin >> b[i];
    }
    sort(a+1, a+x+1);
    sort(b+1, b+y+1);
    for (int i = 1; i <= y; i++) pb[i] = pb[i-1]+b[i];  
    int L = 0, W = 0;
    for (int i = 1; i <= x; i++) {
        int now = a[i];
        int pos = lower_bound(b+1, b+y+1, now) - b;
        int pos2 = upper_bound(b+1, b+y+1, now) - b;
        int win = pos - 1;
        int lose = y-pos2+1;
        debug(now, win, lose);
        W += win;
        L += lose;
    }
    int l = 1, r = x;

    int now = a[x];
    int pos = lower_bound(b+1, b+y+1, now) - b;
    int pos2 = upper_bound(b+1, b+y+1, now) - b;
    int win = pos - 1;
    int lose = y-pos2+1;
    if (lose > win || lose+L >= win+W) {
        cout << -1 << endl;
        return 0;
    }

    while (l < r) {
        int mid_pos = (l+r) / 2;
        int mid = a[mid_pos];
        int pos_in_b_left = lower_bound(b+1, b+y+1, mid) - b; 
        int pos_in_b_right = upper_bound(b+1, b+y+1, mid) - b;
        int cur_win = pos_in_b_left - 1;
        int cur_lost = y - pos_in_b_right + 1;

        if (cur_lost > cur_win || cur_lost+L >= cur_win+W) {
            l = mid_pos+1;
            debug("here", l);
        }
        else {
            r = mid_pos; 
        }
        debug(l, r);
    }
    cout << a[r] << endl;
    return 0;
}

