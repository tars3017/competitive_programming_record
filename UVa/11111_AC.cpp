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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        stringstream ss;
        ss << str;
        ll x;
        stack<ll> s;
        ll now_val = 0;
        bool able = 1;
        int sum = 0;
        while (ss >> x) {
            sum += x;
            if (x < 0) {
                s.push(x);
            }
            else if (x > 0) {
                now_val = 0;
                while (!s.empty() && s.top() != -x) {
                    if (abs(s.top()) >= x) {
                        able = 0;
                        break;
                    }
                    else if (s.top() > 0) {
                        now_val += s.top();
                    }

                    if (now_val >= x) {
                        able = 0;
                        break;
                    }
                    s.pop();
                }
                s.push(x);
                if (s.empty()) able = 0;
            }
        }
        if (s.size() % 2 == 1) able = 0;
        if (sum != 0) able = 0;
        if (able) cout << ":-) Matrioshka!" << endl;
        else cout << ":-( Try again." << endl;
    }
    return 0;
}

