#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
using namespace std;

class String_Calculator {
    public:
        String_Calculator(){};
        String_Calculator(const string);
        String_Calculator& Add(const string);
        String_Calculator& Subtract(const string);
        String_Calculator& DividedBy(const string);
        void output() const;

    private:
        string s = "";
}; //end class String_Calculator

String_Calculator::String_Calculator(const string str) {
    s = str;
}
String_Calculator& String_Calculator::Add(const string str) {
    s += str;
    return *this;
}
String_Calculator& String_Calculator::Subtract(const string str) {
    size_t pos = s.find(str);
    if (pos != string::npos) {
        s.erase(pos, str.size());
    }
    else {
        s = "error";
    }
    return *this;
}
String_Calculator& String_Calculator::DividedBy(const string str) {
    int idx = 0, cnt = 0, x;
    while ( (idx = s.find(str, idx)) != string::npos) {
        ++idx;
        ++cnt;
    }
    s = to_string(cnt);
    return *this;
}

void String_Calculator::output() const{
    cout << s << endl;
}
#endif // FUNCTION_H
