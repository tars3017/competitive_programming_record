#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void printInfix(Node* root) {
    if (root == NULL) return ;
    int print_param = 0;
    if (root->left != NULL) {
        printInfix(root->left);
    }
    printf("%c", root->data);

    if ( root->right != NULL && (root->right->data == '|' || root->right->data == '&') ) {
        printf("(");
        print_param = 1;
    }
    if (root->right != NULL) {
        printInfix(root->right);
    }
    if (print_param) printf(")");
}
