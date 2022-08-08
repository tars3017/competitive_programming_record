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
string to_bin(int x) {
    string re;
    while (x > 0) {
        re.push_back( (x%2) + '0');
        x /= 2;
    }
    while(re.size() < 3) {
        re.push_back('0');
    }
    reverse(re.begin(), re.end());
    return re;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string str;
    getline(cin, str);
    bool next = false;
    vector<pii> ans;
    for (int i = 0; i < n; ++i) {
        next = false;
        ans.clear();
        getline(cin, str);
        char now = str[0];
        int len = 1;
        for (int j = 1; j < str.size(); ++j) {
            if (str[j] != '1' && str[j] != '0') {
                cout << -1 << endl;
                next = true;
                break;
            }
            if (str[j] == now && len < 7) {
                len++;
            }
            else {
                ans.push_back({now-'0', len});
                now = str[j];
                len = 1;
            }
        }
        if (next) continue;
        ans.push_back({now-'0', len});
        for (int j = 0; j < ans.size(); j++) {
            cout << ans[j].F << to_bin(ans[j].S) << ' ';
        }
        cout  << round(400.0*(double)ans.size()/(double)str.size()) << "%" << endl;
    }
    Time();
    return 0;
}

