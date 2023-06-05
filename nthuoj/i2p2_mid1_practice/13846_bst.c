#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node {
    int data;
    struct _Node *l, *r;
}Node;
int layer;
int arr[100005];
int n;
int idx;
int first_print;

Node* build_tree(int lev) {
    if (lev > layer || idx >= n) return NULL; 
    Node* now = (Node*)malloc(sizeof(Node));
    // printf("%d", arr[idx]);
    now->data = arr[idx++];

    now->l = build_tree(lev+1);
    now->r = build_tree(lev+1);
    return now;
}
void dfs(Node* now) {
    if (now == NULL) return;
    if (now->l && now->l->data > now->r->data) {
        Node* tmp = now->l;
        now->l = now->r;
        now->r = tmp;
    }
    dfs(now->l);
    dfs(now->r);
}
void print_tree(Node* now) {
    if (now == NULL) return ;
    // printf("%d ", now->data);
    // if (now->l) printf(" %d", now->l->data);
    // if (now->r) printf(" %d", now->r->data);
    // printf("\n");

    print_tree(now->l);
    print_tree(now->r);
    if (first_print) {
        first_print = 0;
    }
    else {
        printf(" ");
    }
    printf("%d", now->data);
    // print_tree(now->l);
    // print_tree(now->r);
}
int main() {
    scanf("%d", &n);
    layer = log(n+1)/log(2) - 1;
    // printf("layer %d\n", layer);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    idx = 0;
    Node* root = build_tree(0);
    dfs(root);
    first_print = 1;
    print_tree(root);
    printf("\n");
    return 0;
}
