#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    char data;
    struct _Node* next;
    struct _Node* prev;
}Node;
char str[1000005];
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        scanf("%s", str);
        Node* head = (Node*)malloc(sizeof(Node));
        head->data = str[0];
        Node* cursor = (Node*)malloc(sizeof(Node));
        head->prev = NULL;
        head->next = cursor;
        cursor->prev = head;
        cursor->next = NULL;
        cursor->data = ')';
        for (int i = 1; i < n; ++i) {
            if (str[i] == 'L') {
                if (cursor == head) continue;
                cursor = cursor->prev;
            }
            else if (str[i] == 'R') {
                if (cursor->next == NULL) continue;
                cursor = cursor->next;
            }
            else if (str[i] == 'B') {
                if (cursor == head) continue;
                else if (cursor->prev == head) {
                    Node* tmp_head = head;
                    head = cursor;
                    cursor->prev == NULL;
                    free(tmp_head);
                }
                else {
                    Node* prev_tmp = cursor->prev;
                    cursor->prev = prev_tmp->prev;
                    prev_tmp->prev->next = cursor;
                    free(prev_tmp);
                }
            }
            else {
                // printf("add content %c\n", str[i]);
                Node* new_word = (Node*)malloc(sizeof(Node));
                new_word->next = NULL;
                new_word->next = NULL;
                new_word->data = str[i];
                if (cursor == head) {
                    new_word->next = head;
                    new_word->prev = NULL;
                    head->prev = new_word;

                    head = new_word;
                }
                else {
                    Node* prev_tmp = cursor->prev;
                    prev_tmp->next = new_word;
                    new_word->prev = prev_tmp;

                    new_word->next = cursor;
                    cursor->prev = new_word;
                }
            }
        }
        int cnt = 0;
        for (Node* i = head; i != NULL && i->data != ')'; ) {
            ++cnt;
            printf("%c", i->data);
            Node* tmp = i;
            i = i->next;
            free(tmp);
        }
        printf("\n");
        // printf("%d\n", cnt);
    }
    
    
    return 0;
}
