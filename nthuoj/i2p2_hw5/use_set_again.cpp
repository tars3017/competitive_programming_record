#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int get_key(const vector<int> &v) {
    int n = v.size();
    int val = 0;
    for (int i : v) {
        val += n * i;
        --n;
    }
    return val;
}

struct my_cmp {
    bool operator()(const vector<int> &lhs, const vector<int> &rhs) const {
        return get_key(lhs) < get_key(rhs);
    }
};

void print_out(const vector<int> &v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}
int main() {
    set< vector<int>, my_cmp> s;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "insert") {
            int x;
            vector<int> v;
            while (cin >> x && x) {
                v.push_back(x);
            }
            int val = get_key(v);
            for (auto iter = s.begin(); iter != s.end(); iter++) {
                int now_key = get_key(*iter);
                if (now_key == val) {
                    cout << "exist\n";
                    s.erase(iter);
                    reverse(v.begin(), v.end());
                    break;
                }
            }
            s.insert(v);
        }
        else if (cmd == "range_out") {
            vector<int> v1, v2;
            int x;
            while (cin >> x && x) {
                v1.push_back(x);
            }
            while (cin >> x && x) {
                v2.push_back(x);
            }
            int lv = get_key(v1), rv = get_key(v2);
            for (auto iter = s.begin(); iter != s.end(); iter++) {
                if (get_key(*iter) > rv) break;
                if (get_key(*iter) >= lv) {
                    print_out(*iter);
                }
            }
        }
        else if (cmd == "output") {
            for (auto iter = s.begin(); iter != s.end(); iter++) {
                print_out(*iter);
            }
        }
    }
    return 0;
}