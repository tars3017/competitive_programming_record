#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// can't solve A + ( -(C+D) + ( -(E+F) ) )
char str[1005];
typedef struct _Node {
    char data;
    struct _Node *left, *right;
}Node;
int idx;
int len;
Node* build_tree() {
    char ch;
    scanf("%c", &ch);
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        Node* oper = (Node*)malloc(sizeof(Node));
        oper->data = ch;
        ++idx;
        oper->left = build_tree();
        oper->right = build_tree();
        return oper;
    }
    else {
        Node* word = (Node*)malloc(sizeof(Node));
        word->data = ch;
        ++idx;
        word->left = NULL, word->right = NULL;
        return word;
    }
}
void print_tree(Node* now) {
    if (now == NULL) return ;
    if (now->data != '/' && now->data != '*' && now->data != '+' && now->data != '-') {
        printf("%c", now->data);
        return ;
    }
    int left_add_para = 0, right_add_para = 0;
    if (now->data == '*' || now->data == '/') {
        if (now->left != NULL && (now->left->data == '+' || now->left->data == '-') ) {
            left_add_para = 1; 
        }
    }
    if (now->right != NULL) {
        if (now->data == '-') {
            if (now->right->data == '+' || now->right->data == '-') {
                right_add_para = 1;
            }
        }
        else if (now->data == '/') {
            char now_right = now->right->data;
            if (now_right == '+' || now_right == '-' || now_right == '*' || now_right == '/') {
                right_add_para = 1;
            }
        }
        else if (now->data == '*') {
            if (now->right->data == '+' || now->right->data == '-') {
                right_add_para = 1;
            }
        }
    }
    if (left_add_para) printf("(");
    print_tree(now->left);
    if (left_add_para) printf(")");
    printf("%c", now->data);

    if (right_add_para) printf("(");
    print_tree(now->right);
    if (right_add_para) printf(")");
}
int main() {
    // scanf("%s", str);
    // len = strlen(str);
    // idx = 0;
    Node* root = build_tree();
    print_tree(root);
    printf("\n");
    return 0;
}
