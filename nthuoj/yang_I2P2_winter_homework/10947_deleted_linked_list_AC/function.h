#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data) {
    if (data == 1) {
        Node* head = *nd;
        // printf("here %d\n", head->data);
        Node* nxt = head->next;
        // printf("here2 next=%d\n", nxt->data);
        *nd = nxt;
        free(head);
        // printf("new head %d\n", (*nd)->data);
        return ;
    }
    Node* now = *nd;
    while (data > 2 && now->next != NULL) {
        // printf("now = %d next = %d\n", now->data, now->next->data);
        now = now->next;
        --data;
    }
    if (now->next != NULL) {
        if (now->next->next == NULL) {
            free(now->next);
            now->next = NULL;
        }
        else {
            Node* nxt = now->next;
            now->next = nxt->next;
            free(nxt);
        }
    }
}
Node* createList() {
    int num;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* now = head;
    int first = 1;
    while (1) {
        scanf("%d", &num);
        if (num != -1) {
            if (first) {
                now->data = num;
                now->next = NULL;
                first = 0;
            }
            else {
                Node* tmp = (Node*)malloc(sizeof(Node));
                tmp->data = num;
                tmp->next = NULL;
                now->next = tmp;
                now = tmp;
            }
        }
        else break;
    }
    // printf("head=%d\n", head->data);
    return head;
};
