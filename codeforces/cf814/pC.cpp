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
int lose_point[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        memset(arr, 0, sizeof(arr));
        memset(lose_point, -1, sizeof(lose_point));
        int n, q; cin >> n >> q;
        stack<pii> s;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if (s.empty() || arr[i] < s.top().F) {
                s.push( {arr[i], i} );
            }
            else if (arr[i] > s.top().F) {
                while (!s.empty() && arr[i] > s.top().F) {
                    lose_point[s.top().S] = max(i-1, 1); 
                    s.pop();
                }
                s.push( {arr[i], i} );
            }
        }
        int cur_max = 0, max_idx = 0;
        for (int i = 1; i <= n; ++i) {
            if (cur_max > arr[i]) {
                lose_point[i] = max(i-1, 1);
            }
            if (arr[i] > cur_max) {
                cur_max = arr[i];
                max_idx = i;
            }
        }
        if (arr[n] == n) 
            lose_point[n] = n;
        for (int i = 1; i <= n; ++i) {
            debug(i, lose_point[i]);
        }
        while (q--) {
            int idx, rnd; cin >> idx >> rnd;
            if (arr[idx] == n) {
                if (rnd >= idx-1) {
                    debug("here");
                    cout << (idx == 1 ? rnd-idx+1 : rnd-idx+2) << endl;
                }
                else {
                   cout << 0 << endl; 
                }
            }
            else if (idx == 1) {
                if (rnd >= n) rnd = n-1;
                if (rnd == 1) {
                    cout << (arr[1] > arr[2] ? "1" : "0") << endl;
                }
                else if (rnd >= lose_point[idx]) {
                    if (lose_point[idx] == -1) {
                        cout << rnd << endl;
                    }
                    else {
                        cout << max(lose_point[idx]-idx, 0) << endl;
                    }
                }
                else {
                    cout << rnd << endl;
                }
            }
            else {
                if (rnd >= n) rnd = n-1;
                if (rnd < idx-1) {
                    cout << 0 << endl;
                }
                else if (lose_point[idx] == idx-1) {
                    cout << 0 << endl;
                }
                else if (rnd >= lose_point[idx]) {
                    if (lose_point[idx] == -1) {
                        cout << rnd-idx+2 << endl;
                    }
                    else {
                        cout << lose_point[idx]-idx+1 << endl;
                    }
                }
                else {
                    cout << rnd-(idx-1)+1 << endl;
                }
            }
        }
    }
    Time();
    return 0;
}

