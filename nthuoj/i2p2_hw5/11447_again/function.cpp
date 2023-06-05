#include "function.h"
#include <map>
#include <set>
#include <iostream>

using namespace std;

void oj::output(const std::map<int,String> &ma,int begin,int end) {
    for (auto iter = ma.begin(); iter != ma.end(); iter++) {
        if (iter->first > end) break;
        if (iter->first >= begin) {
            cout << iter->second << ' ';
        }
        
    }
}

void oj::insert(std::map<int,String> &ma,int key,const std::string &str) {
    auto iter = ma.find(key);
    String tmp("");
    if (iter != ma.end()) {
        tmp.str = str + iter->second.str;
        ma.erase(iter);
    }
    else {
        tmp.str = str;
    }
    ma.insert(pair<int, String>(key, tmp));
}

void oj::erase(std::map<int,String> &ma,int begin,int end) {
    set<int> eraseKeys;
    for (auto iter = ma.begin(); iter != ma.end(); iter++) {
        if (iter->first > end) {
            break;
        }
        if (iter->first >= begin) {
            eraseKeys.insert(iter->first);
        }
        
    }
    for (int i : eraseKeys) {
        ma.erase(i);
    }
}

std::ostream& oj::operator<<(std::ostream & output, const std::map<int, oj::String> & s) {
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        output << iter->second.str << ' ';
    }
    return output;
}