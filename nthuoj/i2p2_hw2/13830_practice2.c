#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node *left, *right;
}Node;
Node* makeNode(char ch) {
    Node* now = (Node*)malloc(sizeof(Node));
    now->data = ch;
    now->left = NULL, now->right = NULL;
    return now;
}
Node* build_tree() {
    char ch; scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z') {
        return makeNode(ch);
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        Node* now = makeNode(ch);
        now->left = build_tree();
        now->right = build_tree();
        return now;
    }
    else {
        exit(1);
        return NULL;
    }
}
void print_tree(Node* now) {
    if (now == NULL) return ;
    if (now->data >= 'A' && now->data <= 'Z') {
        printf("%c", now->data);
        return ;
    }
    int left_add = 0, right_add = 0;
    char now_ch = now->data;
    char l_ch = now->left->data, r_ch = now->right->data;
    if (now_ch == '*' || now_ch == '/') {
        if (l_ch == '+' || l_ch == '-') {
            left_add = 1;
        }
    }

    if (now_ch == '/') {
        if (r_ch < 'A' || r_ch > 'Z') {
            right_add = 1;
        }
    }
    else if (now_ch == '*') {
        if (r_ch == '+' || r_ch == '-') {
            right_add = 1;
        }
    }
    else if (now_ch == '-') {
        if (r_ch == '+' || r_ch == '-') {
            right_add = 1;
        }
    }

    if (left_add) printf("(");
    print_tree(now->left);
    if (left_add) printf(")");

    printf("%c", now_ch);

    if (right_add) printf("(");
    print_tree(now->right);
    if (right_add) printf(")");
}
int main() {
    Node* root = build_tree();
    print_tree(root);
    printf("\n");
    return 0;
}