#include "function.h"
#include <string>
#include <iostream>
#include <set>
using namespace std;

void oj::insert(std::map<int, String> &ma, int key, const std::string &str) {
    std::map<int, String>::iterator it = ma.find(key);
    
    // notice here!
    String now("");
    if (it != ma.end()) {
        now.str = str + (it->second).str;
        ma.erase(it->first);
    }
    else {
        now.str = str;
    }
    ma.insert(pair<int, String>(key, now));
}

void oj::output(const std::map<int, String> &ma, int begin, int end) {
    for (auto iter = ma.begin(); iter != ma.end(); iter++) {
        if (iter->first > end) break;
        if (iter->first >= begin) cout << iter->second.str << " ";
    }
}

void oj::erase(std::map<int, String> &ma, int begin, int end) {
    set<int> eraseKeys;
    for (auto iter = ma.begin(); iter != ma.end(); iter++) {
        if (iter->first > end) break;
        if (iter->first >= begin) eraseKeys.insert(iter->first);
    }
    for (int i : eraseKeys) {
        ma.erase(i);
    }
}

std::ostream& oj::operator<<(std::ostream & output, const std::map<int, oj::String> &ma) {
    for (auto iter = ma.begin(); iter != ma.end(); iter++) {
        output << iter->second.str << ' ';
    }
    return output;
}