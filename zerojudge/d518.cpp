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

int tree[500005][30];
int pos, n, start;
int num[500005];
void Insert(int now, string str) {
    for (char s : str) {
        if (tree[now][ s - 'a' ] == 0) {
            tree[now][ s - 'a' ] = ++pos;
        }
        now = tree[now][ s - 'a' ];
    }
    if (num[now] != 0) {
        /* cout << "Old! " << num[now] << endl; */
        printf("Old! %d\n", num[now]);
    }
    else {
        num[now] = ++start;
        /* cout << "New! " << num[now] << endl; */
        printf("New! %d\n", num[now]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        memset(tree, 0, sizeof(tree));
        memset(num, 0, sizeof(num));
        start = 0;
        pos = 0;
        string str;
        for (int i = 0; i < n; ++i) {
            cin >> str;
            Insert(0, str);
        }
    }
    Time();
    return 0;
}

