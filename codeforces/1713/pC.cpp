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

vector<int> graph[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    for (int i = 0; i <= 5; ++i) {
        v.push_back(i);
    }
    do {
        bool able = true;
        for (int i = 0; i < v.size(); ++i) {
            int now = sqrt(v[i] + i);
            if (now*now != v[i]+i || v[i]+i == 0) {
                able = false;
                break;
            }
        }
        if (able) {
            for (int i = 0; i < v.size(); ++i) {
                cout << v[i]+i << ' ';
            }
            cout << endl;
            break;
        }
    }while (next_permutation(v.begin(), v.end()));
    debug("end");
    /* int t; cin >> t; */
    /* while (t--) { */
    /*     int n; cin >> n; */
    /*     for (int i = 0; i < n; ++i) { */
    /*         graph[i].clear(); */
    /*         int max_tar = sqrt(i+n-1); */
    /*         for (int j = 1; j <= max_tar; ++j) { */
    /*             graph[i].push_back(j*j - i); */
    /*         } */
    /*     } */

    /* } */
    Time();
    return 0;
}

