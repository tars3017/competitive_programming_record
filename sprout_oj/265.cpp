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

void KMP_build(int* f, string s) {
    f[0] = -1;
    int p = -1;
    for (int i = 1; i < s.size(); ++i) {
        while (p != -1 && s[p+1] != s[i]) {
            p = f[p];
        }
        if (s[p+1] == s[i]) {
            ++p;
        }
        f[i] = p;
    }
}
vector<int> KMP_match(string s, int* f, string t) {
    vector<int> ans;
    int p = -1;
    for (int i = 0; i < t.size(); ++i) {
        while (p != -1 && s[p+1] != t[i]) {
            p = f[p];
        }
        if (s[p+1] == t[i]) {
            ++p;
        }
        if (p+1 == s.size()) {
            ans.push_back(i-p);
            p = f[p];
        }
    }
    return ans;
}
int fail[500005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b; cin >> a >> b;
    KMP_build(fail, a);
    vector<int> res = KMP_match(a, fail, b);
    if (res.empty()) cout << endl;
    else {
        cout << res[0];
        for (int i = 1; i < res.size(); ++i) {
            cout << ' ' << res[i];
        }
        cout << endl;
    }
    return 0;
}

