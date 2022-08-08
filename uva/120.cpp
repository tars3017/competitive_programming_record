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

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    string str;
    stringstream ss;
    vector<int> v, origin;
    int idx[105];
    while (getline(cin, str, '\n')) {
        ss.clear();
        ss << str;
        v.clear();
        origin.clear();
        memset(idx, 0, sizeof(idx));
        int now, tmp = 0;
        while (ss >> now) {
            v.push_back(now);
            origin.push_back(now);
            idx[now] = tmp++;
            // idx.push_back({now, tmp++});
        }
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << " \n"[i==v.size()-1];
        }
        sort(v.begin(), v.end());
        for (int i = origin.size()-1; i >= 0; --i) {
            // cout << "==============" << v[i] << endl;
            if (idx[v[i]] == i) continue;
            else if (idx[v[i]] != 0) {
                // cout << "idx[v[i]]=" << idx[v[i]] << endl;
                int start = 0, end = idx[v[i]];
                cout << origin.size()-end << ' ';
                while (start < end) {
                    // cout << "swap " << start << ' ' << end << endl;
                    swap(idx[origin[start]], idx[origin[end]]);
                    swap(origin[start], origin[end]);
                    start++, end--;
                }
            }
            if (idx[v[i]] != i) {
                int start = 0, end = i;
                // cout << start << "!!!!!" << end << endl;
                cout << origin.size()-end << ' ';
                while (start < end) {
                    swap(idx[origin[start]], idx[origin[end]]);
                    swap(origin[start], origin[end]);
                    start++, end--;
                }
            }
            // for (int j = 0; j < v.size(); ++j) {
            //     cout << origin[j] << ' ';
            // }
            // cout << endl;
            // for (int j = 0; j < v.size(); ++j) {
            //     cout << idx[origin[j]] << ' ';
            // }
            // cout << endl;
        }
        cout << 0 << endl;
    }
    Time();
    return 0;
}

