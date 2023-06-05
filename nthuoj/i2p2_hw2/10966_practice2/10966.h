#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6

#include <stdio.h>
#include <stdlib.h>

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode* EXPR() {
    if (pos < 0) return NULL;

    BTNode *right, *node;
    if ( (expr[pos] >= 'A' && expr[pos] <= 'D') || expr[pos] == ')') {
        right = FACTOR();
        node = right;
    }

    if (expr[pos] == '|' || expr[pos] == '&') {
        node = makeNode(expr[pos]);
        --pos;
        node->right = right;
        node->left = EXPR();
    }
    return node;
}
BTNode* FACTOR() {
    if (pos < 0) return NULL;

    BTNode* now;
    if (expr[pos] == ')') {
        --pos;
        now = EXPR();
        if (expr[pos] != '(') exit(1);
        else --pos;
        return now;
    }
    else if (expr[pos] >= 'A' && expr[pos] <= 'D') {
        return makeNode(expr[pos--]);
    }
}
BTNode* makeNode(char c) {
    BTNode* new_node = (BTNode*)malloc(sizeof(BTNode));
    if (c >= 'A' && c <= 'D') {
        new_node->data = c - 'A';
    }
    else if (c == '|') new_node->data = 5;
    else if (c == '&') new_node->data = 4;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
#endif