#include <assert.h>
#include <stdio.h>

#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;

int people[500005];
long long prefix[500005];
int appear[500005];
Node arr[600005];

Node* head;
Node* createList(int n) {
    int now_age;
    int max_age = 0;
    // printf("debug");
    scanf("\n%d", &now_age);
    ++people[now_age];
    int idx = 1;
    head = &arr[0];
    head->prev = head, head->next = head;
    head->number = 1, head->age = now_age;
    Node* now = head;
    for (int i = 2; i <= n; ++i) {
        scanf(" %d", &now_age);
        max_age = (now_age > max_age ? now_age : max_age);
        ++people[now_age];
        // Node* tmp = (Node*)malloc(sizeof(Node));
        Node* tmp = &arr[idx++];
        tmp->age = now_age, tmp->number = i;

        tmp->next = now->next;
        tmp->prev = now;
        now->next->prev = tmp;
        now->next = tmp;

        now = tmp;
    }
    prefix[0] = people[0];
    for (int i = 1; i <= max_age; ++i) {
        prefix[i] = prefix[i-1] + people[i];
    }
    int j = 1;
    Node* smallest;
    for (Node* i = head; j <= n; i = i->next, ++j) {
        i->number = prefix[(i->age) - 1] + appear[i->age] + 1;
        ++appear[i->age];
        if (i->number == 1) smallest = i;
        // printf("%d -> %d\n", i->age, i->number);
    }
    return smallest;
}
Node* solve(int n, int m) {
    while (m--) {
        int a = -1, k = -1;
        char dir = '!';
        scanf("\n%d %d %c", &a, &k, &dir);
        if (n == 1) continue;
        // printf("here123 %d %d %c\n", a, k, dir);
        k %= (n-1);
        if (k == 0) continue;
        Node* tar = NULL;
        int j = 1;
        // printf("here %d\n", head->age);
        for (Node* i = head; j <= n; ++j, i = i->next) {
            if (i->number == a) {
                tar = i;
                break;
            }
        }
        Node* exchange = tar;
        Node *tar_next, *tar_prev;
        tar_next = tar->next;
        tar_prev = tar->prev;
        if (dir == 'R') {
            while (k--) {
                exchange = exchange->next; 
            }
            tar->next = exchange->next;
            tar->prev = exchange;
            exchange->next->prev = tar;
            exchange->next = tar;

            tar_prev->next = tar_next;
            tar_next->prev = tar_prev;
        }
        else if (dir == 'L') {
            while (k--) {
                exchange = exchange->prev; 
            }
            tar->prev = exchange->prev;
            tar->next = exchange;
            exchange->prev->next = tar;
            exchange->prev = tar;

            tar_prev->next = tar_next;
            tar_next->prev = tar_prev;
        }
        // j = 1;
        // for (Node* i = head; j <= n; ++j, i = i->next) {
        //     printf("i %d\n", i->number);
        // }
    }
    return head;
}

#endif
