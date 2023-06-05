#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value; // This is the value of the subtree, not the ID number
    int tokentype;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent; //pointing to the parent node
}Node;

Node* variable[100005]; 
// and -> -1    or -> -2
int idx;
char str[5000005];
int seq[100005];
void dfs(Node* now) {
    if (now == NULL) return ;
    // printf("now %d %d\n", now->tokentype, now->value);
    dfs(now->leftchild);
    dfs(now->rightchild);
}
Node* build_tree(Node* p) {
    if (str[idx] == '\0') return NULL;

    Node* now = (Node*)malloc(sizeof(Node));
    if (str[idx] == '|' || str[idx] == '&') {
        now->parent = p;
        char now_ch = str[idx];
        ++idx;
        now->leftchild = build_tree(now);
        now->rightchild = build_tree(now);
        
        if (now_ch == '|') {
            now->value = 0; 
            now->tokentype = -2;
        }
        else {
            now->value = 0; 
            now->tokentype = -1;
        }
    }
    else if (str[idx] == '[') {
        char num[10];
        int start_idx = 0;
        ++idx;
        while (str[idx] != ']') {
            num[start_idx] = str[idx];
            ++start_idx;
            ++idx;
            if (str[idx] == '\0') while (1);
        }
        ++idx;
        num[start_idx] = '\0';
        int val = atoi(num);
        // printf("val %d %d\n", start_idx, val);

        now->tokentype = val;
        now->value = 0;
        now->parent = p;
        now->leftchild = now->rightchild = NULL;
        variable[val] = now;
    }
    else {
        exit(1);
    }
    return now;
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        memset(str, 0, sizeof(str));
        memset(seq, 0, sizeof(seq));
        int n, m; scanf("%d %d", &n, &m);
        scanf("%s", str);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &seq[i]);
        }
        idx = 0;
        Node* root = build_tree(NULL);
        // dfs(root);
        // for (int i = 1; i <= n; ++i) {
        //     printf("%d@", variable[i]->value);
        // }
        // printf("\n");
        for (int i = 0; i < m; ++i) {
            Node* now = variable[ seq[i] ];
            now->value = (now->value ? 0 : 1);
            int ans = now->value;
            now = now->parent;
            while (now != NULL) {
                if (now->tokentype == -2) {
                    ans = (now->leftchild->value) | (now->rightchild->value);
                }
                else if (now->tokentype == -1) {
                    ans = (now->leftchild->value) & (now->rightchild->value);
                }
                // printf("%d@%d\n", now->tokentype, now->value);
                now->value = ans;
                now = now->parent;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
