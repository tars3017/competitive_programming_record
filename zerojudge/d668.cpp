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

const int MAXN = 500005;
int n;
pii ST[MAXN*2];
void upd(int i, int x) {
    i += n;
    ST[i].F = x, ST[i].S = x;
    for (i /= 2; i > 0; i /= 2) {
        ST[i].F = max(ST[i*2].F, ST[i*2 + 1].F);
        ST[i].S = min(ST[i*2].S, ST[i*2 + 1].S);
    }
}
int qry(int a, int b) {
    a += n, b += n;
    int max_ans = 0, min_ans = 0x3f3f3f3f;
    while (a <= b) {
        if (a % 2 == 1) {
            max_ans = max(max_ans, ST[a].F);
            min_ans = min(min_ans, ST[a].S);
            a++;
        }
        if (b % 2 == 0) {
            max_ans = max(max_ans, ST[b].F);
            min_ans = min(min_ans, ST[b].S);
            b--;
        }
        a /= 2, b /= 2;
    }
    return (max_ans-min_ans);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        upd(i, num);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << qry(a-1, b-1) << endl;
    }
    Time();
    return 0;
}

