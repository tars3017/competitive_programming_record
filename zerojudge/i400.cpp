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
int m, n; 
string Reverse(string tar) {
    string re;
    for (int i = ceil(n/2.0); i < n; ++i) {
        re.push_back(tar[i]); 
    }
    if (n % 2) {
        re.push_back(tar[ceil(n/2.0)-1]);
        for (int i = 0; i < ceil(n/2.0)-1; ++i) {
            re.push_back(tar[i]);
        }
    }
    else {
        for (int i = 0; i < ceil(n/2.0); ++i) {
            re.push_back(tar[i]);
        }
    }
    return re;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    int cnt[105] = {};
    string arr[105];
    string str1, str2;
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i];
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == '1') cnt[i]++;
        }
    }
    cin >> str1;
    for (int i = m; i > 0; --i) {
        // else {
        //     str2 = str1;
        // }
        deque<char> dq;
        for (int j = n-1; j >= 0; --j) {
            debug(arr[i][j], str1.back());
            if (arr[i][j] == '0') dq.push_front(str1.back());
            else dq.push_back(str1.back());
            str1.pop_back();
        }
        str1.clear();
        for (int j = 0; j < n; ++j) {
            str1.push_back(dq.front());
            dq.pop_front();
        }
        if (cnt[i] % 2) {
            debug("odd");
            str1 = Reverse(str1);
        }
    }
    cout << str1 << endl;
    return 0;
}

