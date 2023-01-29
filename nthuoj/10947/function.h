#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node ** nd, int data) {
    Node* head = *nd;
    int cnt = 1;
    if (data == 1) {
        *nd = head->next;
        /* free(head); */
    }
    else {
        Node* prev = head;
        for (Node* now = head; now != NULL; now = now->next, cnt++) {
            if (cnt == data) {
                if (now->next == NULL) {
                    prev->next = NULL;
                    free(now);
                }
                else {
                    prev->next = now->next;
                    free(now);
                }

                break;
            }
            prev = now;
        }
    }
}
Node* createList() {
    Node* head = malloc(sizeof(Node));
    Node* now = head;
    now->next = NULL;
    int num; 
    while (scanf("%d", &num) && num != -1) {
        // printf("num=%d\n", num);
        Node* tmp = malloc(sizeof(Node));
        tmp->data = num;
        tmp->next = NULL;
        now->next = tmp;
        now = tmp;
    }
    return head->next;
}
