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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while (getline(cin, str)) {
        stringstream ss;
        ss << str;
        char x;
        stack<char> s;
        vector<char> v;
        while (ss >> x) {
            if (x >= 'a' && x <= 'z') {
                v.push_back(x); 
            }
            else if ( (x == '+' || x == '-') && !s.empty() && (s.top() != '(') ) {
                while (!s.empty() && s.top() != '(') {
                    v.push_back(s.top());
                    s.pop();
                }
                s.push(x);
            }
            else if (!s.empty() && (x == '*' || x == '/') && (s.top() == '*' || s.top() == '/') ) {
                while (!s.empty() && ( s.top() == '*' || s.top() == '/' ) ) {
                    v.push_back(s.top());
                    s.pop();
                }
                s.push(x);
            }
            else if (x == ')') {
                while (!s.empty() && s.top() != '(') {
                    v.push_back(s.top());
                    s.pop();
                }
                if (!s.empty() && s.top() == '(') s.pop();
            }
            else {
                debug("here", x);
                if (!s.empty()) debug(s.top());
                s.push(x);
            }
        }
        while (!s.empty()) {
            if (s.top() != '(')
                v.push_back(s.top());
            s.pop();
        }
        for (int i = 0; i < v.size(); ++i) {
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    Time();
    return 0;
}

