#include <stdio.h>
#include <stdlib.h>

int n; 
typedef struct _Node {
    int data;
    struct _Node *left, *right;
}Node;
int pairs[3005][5];
int pos[3005];
int used_pair[3005];
int in_order[3005];
int appear_in_pair[3005];

Node* build(int tar) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = tar;
    for (int i = 1; i <= (n-1)/2; ++i) {
        if (!used_pair[i] && (pos[tar]-pos[pairs[i][0]]) * (pos[tar]-pos[pairs[i][1]]) < 0) {
            if (pos[pairs[i][0]] > pos[pairs[i][1]]) {
                int tmp = pairs[i][0];
                pairs[i][0] = pairs[i][1];
                pairs[i][1] = tmp;
            }
            used_pair[i] = 1;
            node->left = build(pairs[i][0]);
            node->right = build(pairs[i][1]);
        }
    }
    return node;
}
void dfs(Node *now) {
    if (now == NULL) return ;
    printf(" %d", now->data);
    dfs(now->left);
    dfs(now->right);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in_order[i]);
        pos[ in_order[i] ] = i;
    }
    for (int i = 1; i <= (n-1)/2; ++i) {
        scanf("%d %d", &pairs[i][0], &pairs[i][1]);
        appear_in_pair[pairs[i][0]] = 1;
        appear_in_pair[pairs[i][1]] = 1;
    }
    int root_num = 1;
    for (int i = 1; i <= n; ++i) {
        if (!appear_in_pair[i]) {
            root_num = i;
            break;
        }
    }
    Node* root = build(root_num);
    printf("%d", root->data);
    dfs(root->left);
    dfs(root->right);
    printf("\n");
    return 0;
}
