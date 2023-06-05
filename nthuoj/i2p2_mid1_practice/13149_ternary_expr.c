#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _Node {
    int value;
    int var_number;
    struct _Node *left, *right;
}Node;
char str[500005];
int binary[50005];
Node* var_addr[50005];
int var_cnt;
int idx, len;

Node* TRY_EXPR() {
    if (idx >= len) return NULL;
    
    // ++var_cnt;
    int start_idx = 0;
    char num[10];
    while (idx < len && str[idx] >= '0' && str[idx] <= '9') {
        // printf("now read %c\n", str[idx]);
        num[start_idx] = str[idx];
        ++start_idx;
        ++idx;
    }
    num[start_idx] = '\0';

    // Node* now = (Node*)malloc(sizeof(Node));
    int val = atoi(num);
    // scanf("%d", &val);
    var_cnt = (val > var_cnt ? val : var_cnt);
    var_addr[val]->var_number = val;
    Node* now = var_addr[val];

    // var_addr[val] = now;
    // now->var_number = val;
    var_addr[val]->left = var_addr[val]->right = NULL;
    
    char next_ch;
    // scanf("%c", &next_ch);
    if (idx < len && str[idx] == '?') {
        ++idx;
        now->left = TRY_EXPR();
        ++idx;
        now->right = TRY_EXPR();
    }
    return now;
}
int eval(Node* root) {
    if (root == NULL) {
        assert(0);
        return 0;
    }
    
    // printf("number %d %d\n", root->var_number, binary[root->var_number]); 
    // if (root->left == NULL) printf("leaf\n");
    // else if (root->right == NULL) printf("right null\n");
    // else {
    //     printf("left %d %d\n", root->left->var_number, root->right->var_number);
    // }
    int now_val = binary[root->var_number];
    if (root->left == NULL || root->right == NULL) return now_val;
    
    if (now_val) return eval(root->left);
    else return eval(root->right); 
}
void dfs(Node* root) {
    if (root == NULL) return ;
    printf("%d", root->var_number);
    if (root->left != NULL) printf(" left %d ", root->left->var_number);
    if (root->right != NULL) printf(" right %d ", root->right->var_number);
    printf("\n");
    dfs(root->left);
    dfs(root->right);
}

char bit_str[5005];
char last_str[5005];
int main() {
    for (int i = 0; i <= 5000; ++i) {
        var_addr[i] = (Node*)malloc(sizeof(Node));
        var_addr[i]->left = NULL;
        var_addr[i]->right = NULL;
    }
    scanf("%s", str);
    len = strlen(str);
    idx = 0;
    Node* root = TRY_EXPR(); 
    // dfs(root);
    int t; scanf("%d", &t);
    // printf("var %d\n", var_cnt);
    while (t--) {
        memset(binary, 0, sizeof(binary));
        char ch;
        scanf("\n");
        for (int i = 1; i <= var_cnt; ++i) {
            scanf("%c", &ch);
            binary[i] = (ch == '0' ? 0 : 1);
            // printf("binary %d\n", binary[i]);
        }
        printf("%d\n", eval(root));
    }
    return 0;
}
