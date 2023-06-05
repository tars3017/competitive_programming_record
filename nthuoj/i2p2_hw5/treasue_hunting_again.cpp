#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<node> Q;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
        Q.push(node(x, 0));
    }
    fill(Dist, Dist+100005, -1);

    while (!Q.empty()) {
        node now = Q.front();
        Q.pop();
        Dist[now.id] = (Dist[now.id] == -1 || Dist[now.id] > now.dist ? now.dist : Dist[now.id]);
        for (int j : G[now.id]) {
            if (Dist[j] == -1) {
                Q.push(node(j, now.dist+1));
            }
        }
    }

    // [TODO] complete the task!
    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}