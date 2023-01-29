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

int arr[1000005];
vector<int> big, small;
int main() {
    /* ios_base::sync_with_stdio(false); */
    /* cin.tie(0); */
    int n, k;
    multiset<int> ms;
    while (cin >> n >> k) {
        k = min(k, n);
        memset(arr, 0, sizeof(arr));
        big.clear();
        small.clear();
        ms.clear();
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for (int i = 0; i < k; ++i) {
            ms.insert(arr[i]);
        }
        small.push_back(*ms.begin());
        big.push_back(*ms.rbegin());
        for (int i = 1; i+k-1 < n; ++i) {
            ms.erase(arr[i-1]);
            ms.insert(arr[i+k-1]);
            small.push_back(*ms.begin());
            big.push_back(*ms.rbegin());
            /* for (auto iter = ms.begin(); iter != ms.end(); iter++) { */
            /*     cout << *iter << ' '; */
            /* } */
            /* cout << endl; */
        }
        for (int i = 0; i < small.size(); ++i) {
            cout << small[i] << " \n"[i==small.size()-1];
        }
        for (int i = 0; i < big.size(); ++i) {
            cout << big[i] << " \n"[i==big.size()-1];
        }
    }
    Time();
    return 0;
}

