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

int arr[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int idx = n-1;
        while (idx > 0 && (arr[idx] >= arr[idx-1])) {
            idx--;
        }
        if (idx == 0) {
            cout << 0 << endl;
            continue;
        }
        set<int> s;
        for (int i = 0; i < idx; ++i) {
            s.insert(arr[i]);
            arr[i] = 0;
        }
        while (1) {
            bool clean = true;
            bool turn = false;
            for (int i = n-1; i >= 0 && arr[i]; --i) {
                if (s.count(arr[i]) || turn) {
                    s.insert(arr[i]);
                    turn = true;
                    clean = false;
                    arr[i] = 0;
                }
            }
            if (clean) break;
        }
        cout << s.size() << endl;
    }
    Time();
    return 0;
}

