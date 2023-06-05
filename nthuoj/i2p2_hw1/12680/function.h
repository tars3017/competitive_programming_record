#include <stdio.h>
#ifndef __FUNCTION_H__
#define __FUNCTION_H__
typedef struct _Node{
    int size;
    int* data;
    struct _Node* next;
} Node;

int min (int a, int b) {
    return (a < b ? a : b);
}
Node* ReadOneList() {
    int n; scanf("%d:", &n);
    Node* now = (Node*)malloc(sizeof(Node*));
    now->data = (int*)malloc(sizeof(int)*(n+5));
    now->size = n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", (now->data)+i); 
    }
    return now;
}
void PrintList(Node* dummy_head) {
    for (Node* i = dummy_head->next; i != NULL; i = i->next) {
        printf("%d", *(i->data));
        for (int j = 1; j < i->size; ++j) {
            printf(" %d", *( (i->data)+j ));
        }
        printf("\n");
    }
}
void Merge(Node* dummy_head, int x, int y) {
    Node *x_stack, *y_stack, *prev_x;
    int j = 1;
    for (Node* i = dummy_head->next; i != NULL; i = i->next, ++j) {
        if (j == x) {
            x_stack = i;
        }
        else if (j == y) {
            y_stack = i;
        }
        
        if (j+1 == x) prev_x = i;
    }
    int new_size = x_stack->size + y_stack->size;
    int* new_arr = (int*)malloc(sizeof(int) * (new_size + 5));
    for (int i = 0; i < y_stack->size; ++i) {
        new_arr[i] = *( (y_stack->data)+i );
    }
    for (int i = 0; i < x_stack->size; ++i) {
        // printf("content %d\n", *((x_stack->data) + i));
        new_arr[i + y_stack->size] = *( (x_stack->data) + i);
    }
    free(y_stack->data);
    y_stack->size = new_size;
    y_stack->data = new_arr;
    
    prev_x->next = x_stack->next;
    free(x_stack);
}
void Cut(Node* dummy_head, int x, int idx) {
    Node* tar;
    int j = 1;
    for (Node* i = dummy_head->next; i != NULL; i = i->next, ++j) {
        if (j == x) {
            tar = i;
            break;
        }
    }
    int new_size = tar->size - idx;
    int* new_arr = (int*)malloc(sizeof(int)*(new_size+5));
    for (int i = 0; i+idx < tar->size; ++i) {
        // printf("[%d] %d\n", i, * ((tar->data)+i+idx));
        new_arr[i] = * ((tar->data) + i + idx);
    }
    realloc(tar->data, sizeof(int)*(min(idx+5, tar->size)));
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->size = new_size;
    new_node->data = new_arr;
    new_node->next = tar->next;
    tar->next = new_node;
    tar->size = idx;
}

#endif
