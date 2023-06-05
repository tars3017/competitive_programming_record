#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int data;
    int left, right, parent;
}Node;
Node arr[3005];

int vis[3005];
char steps[3005];
int in_deg[3005];
int finish;
void dfs(Node now, int target, int idx) {
    // printf("%d l %d r %d p %d\n", now.data, now.left, now.right, now.parent);
    if (now.data == 0 || finish) return ;
    if (now.data == target) {
        finish = 1;
        for (int i = 0; i < idx; ++i) {
            printf("%c", steps[i]);
        }
        printf("\n");
    }
    if (now.parent && !vis[now.parent]) {
        vis[now.parent] = 1;
        steps[idx] = 'P';
        dfs(arr[now.parent], target, idx+1); 
        vis[now.parent] = 0;
    }
    if (now.left && !vis[now.left]) {
        vis[now.left] = 1;
        steps[idx] = 'L';
        dfs(arr[now.left], target, idx+1); 
        vis[now.left] = 0;
    }
    if (now.right && !vis[now.right]) {
        vis[now.right] = 1;
        steps[idx] = 'R';
        dfs(arr[now.right], target, idx+1); 
        vis[now.right] = 0;
    }
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        arr[i].data = i;
        int a, b;
        scanf("%d %d", &a, &b);
        if (a) {
            arr[a].parent = i;
            arr[i].left = a;
            in_deg[a]++;
        }
        else {
            arr[i].left = 0;
        }
        if (b) {
            arr[b].parent = i;
            arr[i].right = b;
            in_deg[b]++;
        }
        else {
            arr[i].right = 0; 
        }
    }
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0) {
            root = i;
            arr[i].parent = 0;
            break;
        }
    }
    int t; scanf("%d", &t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(steps, 0, sizeof(steps));
        int a, b; scanf("%d %d", &a, &b);
        finish = 0;
        vis[a] = 1;
        dfs(arr[a], b, 0);
    }
    return 0;
}
