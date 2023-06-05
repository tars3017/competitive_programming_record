#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int get_key(vector<int> v) {
    int sz = v.size();
    int ans = 0;
    for (int i : v) {
        ans += sz * i;
        --sz;
    }
    return ans;
}
struct my_cmp {
    bool operator() (const vector<int> &lhs, const vector<int> &rhs) const {
        return get_key(lhs) < get_key(rhs);
    }
};
void output_vec(vector<int> v) {
    // if (v.empty()) return ;
    // cout << v[0];
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;
}
int main() {
    string cmd;
    set< vector<int>, my_cmp > s;
    while (cin >> cmd) {
        if (cmd == "output") {
            for (set< vector<int>, my_cmp>::iterator iter = s.begin(); iter != s.end(); iter++) {
                output_vec(*iter);
            }
            // cout << "output finished" << endl;
        }
        else if (cmd == "insert") {
            vector<int> now;
            int x;
            while (cin >> x && x) {
                now.push_back(x);
            }
            int val = get_key(now);
            for (auto iter = s.begin(); iter != s.end(); iter++) {
                if (get_key(*iter) == val) {
                    s.erase(iter);
                    reverse(now.begin(), now.end());
                    break;
                }
            }
            s.insert(now);
            // cout << "insert finished" << endl;
        }
        else if (cmd == "range_out") {
            vector<int> a, b;
            int x;
            while (cin >> x && x) {
                a.push_back(x);
            }
            while (cin >> x && x) {
                b.push_back(x);
            }
            int v1 = get_key(a);
            int v2 = get_key(b);
            for (auto iter = s.begin(); iter != s.end(); iter++) {
                if (get_key(*iter) < v1) continue;
                if (get_key(*iter) > v2) break;
                output_vec(*iter);
            }
            // cout << "range out" << endl;
        }
    }
    return 0;
}