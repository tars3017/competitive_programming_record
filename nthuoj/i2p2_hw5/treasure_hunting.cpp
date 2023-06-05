#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
bool has_diamond[100005];
vector<int> G[100005];
int Dist[100005];
bool vis[100005];

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

void clear(queue<node> &q) {
    queue<node> empty;
    swap(q, empty);
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fill(Dist, Dist+100005, -1);
    // flood fill
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
        has_diamond[x] = 1;
        Dist[x] = 0;
    }

    queue<node> Q;
    for (int i = 0; i < K; ++i) {
        Q.push(node(diamondTowns[i], 0));
    }
    int now_len = 0;
    while (!Q.empty()) {
        while (!Q.empty() && Q.front().dist == now_len) {
            node now = Q.front();
            Q.pop();
            Dist[now.id] = (Dist[now.id] == -1 || now_len < Dist[now.id] ? now_len : Dist[now.id]);
            for (int j : G[now.id]) {
                if (Dist[j] == -1) {
                    Q.push(node(j, now_len+1));
                }
            }
        }
        ++now_len; 
    }
    
    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}