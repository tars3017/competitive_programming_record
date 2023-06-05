#include<iostream>
#include<string>
#include"function.h"
using namespace std;


String_Calculator::String_Calculator(const string str) {
    s = str;
}
String_Calculator& String_Calculator::Add(const string b) {
    s += b;
    // cout << "after add " << s << endl;
    return *this;
}
String_Calculator& String_Calculator::Subtract(const string b) {
    size_t found = s.find(b);
    if (found != string::npos) {
        s.erase(found, b.size());
    }
    else {
        s = "error";
    }
    cout << "after erase " << s << endl;
    return *this;
}
String_Calculator& String_Calculator::DividedBy(const string b) {
    int cnt = 0;
    size_t pos = 0;
    int now_idx;
    while ( (now_idx = s.find(b, pos)) != string::npos) {
        ++cnt;
        // cout << "find at " << pos << endl;
        //pos = now_idx + b.size();
        pos = now_idx + 1;
    }
    // cout << "divide " << cnt << endl;
    // cout << cnt << endl;
    s = to_string(cnt);
    return *this;
}
void String_Calculator::output() const {
    cout << s << endl;
}
int main(){
    int n;
    string x, y;
    cin >> n;
    while(n--){
        cin >> x >> y;
        String_Calculator a(x), ans;
        ans = a.Subtract(y).Add(y).DividedBy(y);
        ans.output();
    }
}
