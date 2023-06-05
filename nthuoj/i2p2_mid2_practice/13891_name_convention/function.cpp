#include "function.h"
#include <sstream>

void CamelCase::convert() {
    stringstream ss;
    ss << name;
    string ans = "";
    while (!ss.eof()) {
        string one_word;
        getline(ss, one_word, '-');
        one_word[0] = toupper(one_word[0]);
        // cout << "to uppper " << one_word << endl;;
        ans += one_word;
    }
    name = ans;
    converted = true;
}

void CamelCase::revert() {
    string ans = "";
    for (int i = 0; i < name.size(); ++i) {
        if (isupper(name[i])) {
            if (i > 0) ans += '-';
        }
        ans += tolower(name[i]);
    }
    name = ans;
    converted = false;
}
