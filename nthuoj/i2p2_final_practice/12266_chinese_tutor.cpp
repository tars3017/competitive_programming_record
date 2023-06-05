#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> mp = {
    {"Wa", "Waninoko"},
    {"Mi", "Milotic"},
    {"Ma", "Magikarp"},
    {"Va", "Vaporeon"},
    {"Sh", "Sharpedo"},
    {"Tapu", "Tapu Fini"},
    {"Em", "Empoleon"},
    {"La", "Lapras"},
    {"Pi", "Pikachu"},
    {"Pe", "Pikachu"},
    {"Me", "Mega Gyarados"}
};
int main() {
    int n; cin >> n;
    string name, school;
    for (int i = 0; i < n; ++i) {
        cin >> name >> school;
        bool suit = false;
        for (pair<string, string> x : mp) {
            // cout << "sub " << name.substr(0, x.first.size()) << ' ' << x.second << endl;
            if (name.substr(0, x.first.size()) == x.first) {
                suit = true;
                cout << name << " the " << school << ' ' << x.second << endl;
                break;
            }
        }
        if (!suit) cout << name << " is looking for a Chinese tutor, too!" << endl;
    }
    return 0;
}