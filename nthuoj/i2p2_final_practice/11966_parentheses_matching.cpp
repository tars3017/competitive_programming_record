#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

map<char, char> mp = {{'{', '}'}, {'[', ']'}, {'<', '>'}, {'(', ')'}};
int main() {
    int n; cin >> n;
    string str;
    getline(cin, str);
    for (int i = 1; i <= n; ++i) {
        stack<char> s;
        getline(cin, str);
        bool valid = true;
        for (char c : str) {
            if (c == '{' || c == '[' || c == '(' || c == '<') {
                s.push(c);
            }
            else if (c == '}' || c == ']' || c == ')' || c == '>') {
                if (s.empty() || mp[s.top()] != c) {
                    valid = false;
                    break;
                }
                else {
                    s.pop();
                }
            }
        }
        if (!s.empty()) valid = false;
        cout << "Case " << i << ": " << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}