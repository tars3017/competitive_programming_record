#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *left, *right;
}Node;
int arr[3005];
int pairs[3005][5];
int pos[3005];
int appear[3005];
int used[3005];
int pair_len;

Node* make_node(int num) {
    Node* now = (Node*)malloc(sizeof(Node));
    now->data = num;
    now->left = NULL;
    now->right = NULL;
    return now;
}
Node* build_tree(int tar) {
    int l_child = -1, r_child = -1;
    for (int i = 1; i <= pair_len; ++i) {
        if (used[i]) continue;
        if ( (pos[tar] - pos[ pairs[i][0] ]) * (pos[tar] - pos[ pairs[i][1] ]) < 0) {
            l_child = pairs[i][0];
            r_child = pairs[i][1];
            if (pos[l_child] > pos[r_child]) {
                int tmp = l_child;
                l_child = r_child;
                r_child = tmp;
            }
            used[i] = 1;
            break;
        }
    }
    Node* now = make_node(tar);
    if (l_child == -1) {
        now->left = NULL;
        now->right = NULL;
    }
    else {
        now->left = build_tree(l_child);
        now->right = build_tree(r_child);
    }
    return now;
}
void dfs(Node* now) {
    if (now == NULL) return ;
    printf(" %d", now->data);
    dfs(now->left);
    dfs(now->right);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        pos[ arr[i] ] = i;
    }
    pair_len = (n-1) / 2;
    for (int i = 1; i <= (n-1)/2; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        pairs[i][0] = a;
        pairs[i][1] = b;
        appear[a] = 1;
        appear[b] = 1;
    }
    int root_num;
    for (int i = 1; i <= n; ++i) {
        if (!appear[i]) {
            root_num = i;
            break;
        }
    }
    Node* root = build_tree(root_num);

    printf("%d", root_num);
    dfs(root->left);
    dfs(root->right);
    printf("\n");
    return 0;
}
