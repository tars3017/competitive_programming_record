#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;

int cmp(const void* a, const void* b) {
    Node* c = *(Node**)a;
    Node* d = *(Node**)b;
    if (c->age == d->age) return c->number > d->number;
    return (c->age) > (d->age);
}
Node* arr[500005];
Node* head;
Node* createList(int n) {
    arr[0] = (Node*)malloc(sizeof(Node));
    arr[0]->number = 0;
    scanf("%d", &(arr[0]->age));
    for (int i = 1; i < n; ++i) {
        arr[i] = (Node*)malloc(sizeof(Node));
        arr[i]->number = i;
        scanf("%d", &(arr[i]->age));
        arr[i]->prev = arr[i-1];
        arr[i-1]->next = arr[i];
    }
    arr[n-1]->next = arr[0];
    arr[0]->prev = arr[n-1];
    qsort(arr, n, sizeof(Node*), cmp);
    return arr[0];
}
Node* solve(int n, int m) {
    while (m--) {
        int a, k; char dir;
        scanf("%d %d %c", &a, &k, &dir);
        Node* now = arr[a-1];
        Node* tar = now;
        k %= (n-1);
        if (k == 0) continue;
        if (dir == 'R') {
            while (k--) tar = tar->next;
        }
        else if (dir == 'L') {
            while (k--) tar = tar->prev;
            tar = tar->prev;
        }
        Node *now_prev = now->prev, *now_next = now->next;
        now->next = tar->next;
        now->prev = tar;
        tar->next->prev = now;
        tar->next = now;

        now_prev->next = now_next;
        now_next->prev = now_prev;

        // for (Node* i = arr[0]; ; i = i->next) {
        //     printf("%d %d\n", i->number, i->age);
        //     if (i->next == arr[0]) break;
        // }
        // printf("=======\n");
    }
    return arr[0];
}

#endif
