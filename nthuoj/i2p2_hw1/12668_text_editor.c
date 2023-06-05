#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000005];
typedef struct _Node {
    char ch;
    struct _Node* next;
    struct _Node* prev;
}Node;
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("\n%d", &n);
        memset(str, 0, sizeof(str));
        scanf("\n%s", str);
        Node* head = (Node*)malloc(sizeof(Node));
        Node* now = (Node*)malloc(sizeof(Node));
        head->prev = NULL;
        head->ch = '*';
        now->prev = head;
        head->next = now;
        now->ch = '@'; // now is cursor
        now->next = NULL;
        for (int i = 0; i < n; ++i) { 
            if (str[i] == 'B' || str[i] == 'R' || str[i] == 'L') {
                if (str[i] == 'B') {
                    if (now->prev == NULL) continue;
                    else if (now->prev == head) {
                        head->ch = '*';
                    }
                    else {
                        Node* prev_word = now->prev;
                        now->prev = prev_word->prev;
                        prev_word->prev->next = now;
                        free(prev_word);
                    }
                }
                else if (str[i] == 'R') {
                    if (now->next == NULL) continue;
                    else {
                        now = now->next;
                    }
                }
                else if (str[i] == 'L') {
                    if (now->prev == NULL) continue;
                    else {
                        now = now->prev;
                    }
                }
            }
            else if (now == head) {
                Node* tmp = (Node*)malloc(sizeof(Node));
                tmp->ch = str[i];
                tmp->next = NULL;
                tmp->prev = NULL;
                tmp->next = now;
                now->prev = tmp;
                head = tmp;
            }
            else if (now->prev->ch == '*') {
                now->prev->ch = str[i];
            }
            else {
                Node* tmp = (Node*)malloc(sizeof(Node));
                tmp->ch = str[i];
                tmp->next = NULL;
                tmp->prev = NULL;
                
                tmp->prev = now->prev;
                now->prev->next = tmp;
                tmp->next = now;
                now->prev = tmp;

            }
            // for (Node* i = head; i != NULL; ) {
            //     printf("%c", i->ch);
            //     Node* tmp_next = i->next;
            //     i = tmp_next;
            // }
            // printf("\n");
        }
        Node* i;
        for (i = head; i != NULL; ) {
            if (i->ch != '*' && i->ch != '@')
                printf("%c", i->ch);
            Node* tmp_next = i->next;
            free(i);
            i = tmp_next;
        }
        free(i);
        printf("\n");
    }
    return 0;
}
