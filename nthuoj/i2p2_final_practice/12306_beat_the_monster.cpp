#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int lev, hp, mhp, round;
    node(int _lev, int _hp, int _mhp, int _r): lev(_lev), hp(_hp), mhp(_mhp), round(_r) {}
    node(): lev(0), hp(0), mhp(0), round(1) {}
};
pair<int, int> arr[20];
queue<node> q;
bool vis[20][305][405];
int main() {
    int L, HP, MHP, MDMG;
    cin >> L >> HP >> MHP >> MDMG;
    for (int i = 1; i <= L; ++i) {
        cin >> arr[i].first >> arr[i].second;
        // damgge heal
    }
    
    q.push(node(1, HP, MHP, 0));  
    bool beat = false;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        
        if (now.mhp <= 0) {
            cout << now.round << endl;
            beat = true;
            break;
        }
        if (now.hp <= 0) continue;

        if ( !(now.mhp - arr[now.lev].first > 0 && now.hp - MDMG <= 0) && arr[now.lev].first > 0) {
            node t(now.lev, now.hp - MDMG, max(now.mhp - arr[now.lev].first, 0), now.round + 1);
            if (!vis[t.lev][t.hp][t.mhp]) {
                vis[t.lev][t.hp][t.mhp] = 1;
                q.push(t);
            }
        }
        // notice here!!! 
        if (arr[now.lev].second > MDMG && now.hp < HP) {
            node t(now.lev, min(now.hp + arr[now.lev].second, HP) - MDMG, now.mhp, now.round+1);
            if (!vis[t.lev][t.hp][t.mhp]) {
                vis[t.lev][t.hp][t.mhp] = 1;
                q.push(t);
            }
        }
        if (now.hp > MDMG && now.lev < L) {
            node t(now.lev+1, now.hp - MDMG, now.mhp, now.round+1);
            if (!vis[t.lev][t.hp][t.mhp]) {
                vis[t.lev][t.hp][t.mhp] = 1;
                q.push(t);
            }
        }
    }
    if (!beat) {
        cout << -1 << endl;
    }
    return 0;
}