#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM] = "ABCD&|";

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;
BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char);

BTNode* EXPR() {
    char c;
    BTNode *now = NULL, *right = NULL;
    
    if (pos >= 0) {
        c = expr[pos];
        if ((c >= 'A' && c <= 'D') || c == ')') {
            right = FACTOR();
        }

        if (pos > 0) {
            c = expr[pos];
            if (c == '&' || c == '|') {
                --pos;
                now = makeNode(c);
                now->right = right;
                now->left = EXPR();
            }
            else {
                now = right;
            }
        }
        else {
            now = right;
        }
    }
    return now;
}
BTNode* FACTOR() {
    char c;
    BTNode* now = NULL;

    if (pos >= 0) {
        c = expr[pos--];
        if (c >= 'A' && c <= 'D') {
            now = makeNode(c);
        }
        else if (c == ')') {
            now = EXPR();
            if (expr[pos--] != '(') {
                printf("compile error\n");
                exit(0);
            }
        }
    }
    return now;
}
BTNode* makeNode(char c) {
    BTNode* now = (BTNode*)malloc(sizeof(BTNode));
    for (int i = 0; i < NUMSYM; ++i) {
        if (c == sym[i]) {
            now->data = i;
            break;
        }
    }
    now->left = NULL;
    now->right = NULL;
    return now;
}
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

#endif