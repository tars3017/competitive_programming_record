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

struct Node {
    int idx, cnt;
    Node (int _idx = 0, int _cnt = 0) {
        idx = _idx;
        cnt = _cnt;
    }
};
bool cmp(Node a, Node b) {
    if (a.cnt != b.cnt) {
        return a.cnt < b.cnt;
    }
    return a.idx > b.idx;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str; 
    bool first = true;
    while (getline(cin, str)) {
        Node arr[300];
        for (int i = 0; i < 300; ++i) {
            arr[i] = Node();
        }
        for (int i = 0; i < str.size(); ++i) {
            arr[str[i]].idx = str[i];
            arr[str[i]].cnt++;
        }
        sort(arr, arr+300, cmp);
        if (!first) cout << endl;
        else first = false;
        for (int i = 0; i < 300; ++i) {
            if (arr[i].cnt) {
                cout << arr[i].idx << ' ' << arr[i].cnt << endl;
            }
        }
    }
    Time();
    return 0;
}

