#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cmd[20];
char cmd2[20];
int A, B;
int cmd_type;

typedef struct _Node {
    int data;
    struct _Node *next, *prev;
}Node;
typedef struct _Pile {
    Node *head, *tail;
    // int sz;
}pile;

pile piles[30];
Node* addr[30];
int in_stack[30];
void clear_above(Node* now) {
    while (now != NULL) {
        Node* tmp = now->next;
        
        if (piles[now->data].tail == NULL) {
            now->prev = NULL;
            piles[now->data].head = now;
            piles[now->data].tail = now;
        }
        else {
            now->prev = piles[now->data].tail;
            piles[now->data].tail->next = now;
            piles[now->data].tail = now;
        }
        in_stack[now->data] = now->data;
        now->next = NULL;

        now = tmp;
    }
}

void print_stack(int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d:", i);
        Node* now = piles[i].head;
        while (now != NULL) {
            printf(" %d", now->data);
            now = now->next;
        }
        printf("\n");
    }
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        piles[i].head = (Node*)malloc(sizeof(Node));
        piles[i].tail = piles[i].head;
        piles[i].head->data = i;
        piles[i].head->next = NULL;
        piles[i].head->prev = NULL;

        addr[i] = piles[i].head;
        in_stack[i] = i;
    }
    while (scanf("%s", cmd)) {
        if (!strcmp(cmd, "exit")) {
            break;
        }
        scanf("%d %s %d", &A, cmd2, &B);
        if (in_stack[A] == in_stack[B]) {
            continue;
        }

        if (!strcmp(cmd, "move")) {
            if (!strcmp(cmd2, "onto")) {
                cmd_type = 1;
            }
            else if (!strcmp(cmd2, "over")) {
                cmd_type = 2;
            }
        }
        else if (!strcmp(cmd, "pile")) {
            if (!strcmp(cmd2, "onto")) {
                cmd_type = 3;
            }
            else if (!strcmp(cmd2, "over")) {
                cmd_type = 4;
            }
        }
        // printf("cmd type %d\n", cmd_type);
        Node *a = addr[A], *b = addr[B];
        if (cmd_type == 1) {
            clear_above(a->next);
            clear_above(b->next);
            if (a->prev == NULL) {
                piles[ in_stack[a->data] ].head = NULL;
                piles[ in_stack[a->data] ].tail = NULL;
            }
            else {
                piles[ in_stack[a->data] ].tail = a->prev;
                a->prev->next = NULL;
            }

            b->next = a;
            a->prev = b;
            in_stack[ a->data ] = in_stack [ b->data ];
            piles[ in_stack[a->data] ].tail = a; 
            a->next = NULL;
        }
        else if (cmd_type == 2) {
            clear_above(a->next);
            if (a->prev == NULL) {
                piles[ in_stack[a->data] ].head = NULL;
                piles[ in_stack[a->data] ].tail = NULL;
            }
            else {
                piles[ in_stack[a->data] ].tail = a->prev;
                a->prev->next = NULL;
            }

            b = piles[ in_stack[b->data] ].tail;
            // printf("now b tail %d\n", b->data);
            b->next = a;
            a->prev = b;
            in_stack[ a->data ] = in_stack[ b->data ];
            piles[ in_stack[a->data] ].tail = a;
            a->next = NULL;
        }
        else if (cmd_type == 3) {
            clear_above(b->next);
            Node* a_origin_tail = piles[ in_stack[a->data] ].tail;
            if (a->prev == NULL) {
                piles[ in_stack[a->data] ].head = NULL;
                piles[ in_stack[a->data] ].tail = NULL;
            }
            else {
                piles[ in_stack[a->data] ].tail = a->prev;
                a->prev->next = NULL;
            }

            b->next = a;
            a->prev = b;
            Node* now = a;
            // don't forget to change all the in_stack number above A!
            while (now != NULL) {
                in_stack[now->data] = in_stack[ b->data ];
                now = now->next;
            }
            piles[ in_stack[b->data] ].tail = a_origin_tail;
        }
        else if (cmd_type == 4) {
            Node* a_origin_tail = piles[ in_stack[a->data] ].tail;
            if (a->prev == NULL) {
                piles[ in_stack[a->data] ].head = NULL;
                piles[ in_stack[a->data] ].tail = NULL;
            }
            else {
                piles[ in_stack[a->data] ].tail = a->prev;
                a->prev->next = NULL;
            }

            b = piles[ in_stack[b->data] ].tail;
            b->next = a;
            a->prev = b;
            Node* now = a;
            while (now != NULL) {
                in_stack[now->data] = in_stack[b->data];
                now = now->next;
            }
            piles[ in_stack[b->data] ].tail = a_origin_tail;
        }
    }
    print_stack(n);
    return 0;
}
