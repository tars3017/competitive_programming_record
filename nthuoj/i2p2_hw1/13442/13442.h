#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct _Node{
    int number, age;
    struct _Node* prev;
    struct _Node* next;
}Node;

Node* head;
// Node* createList(int n);

int cmp(const void* p, const void* q) {
    Node *a = *(Node**)p;
    Node *b = *(Node**)q;
    if ((a->age) == (b->age)) return (a->number) > (b->number);
    return (a->age) > (b->age);
}
Node* arr[500005];
Node* createList(int n) {
    int idx = 1;
    arr[0] = (Node*)malloc(sizeof(Node));
    scanf("%d", &(arr[0]->age));
    arr[0]->number = 0;

    for (int i = 1; i < n; ++i) {
        arr[i] = (Node*)malloc(sizeof(Node));
        arr[i]->prev = arr[i-1];
        arr[i-1]->next = arr[i];
        scanf("%d", &(arr[i]->age));
        arr[i]->number = i;
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
        k %= (n-1);
        if (k == 0) continue;
        Node* now = arr[a-1];
        Node* tar = now;
        if (dir == 'R') {
            while (k--) tar = tar->next; 
        }
        else if (dir == 'L') {
            while (k--) tar = tar->prev;
            tar = tar->prev;
        }
        // printf("tar %d\n", tar->age);
        Node *now_next = now->next, *now_prev = now->prev;
        now->next = tar->next;
        now->prev = tar;

        tar->next->prev = now;
        tar->next = now;

        now_next->prev = now_prev;
        now_prev->next = now_next;
        int cnt = 0;
        // for (Node* i = arr[0]; cnt < n; i = i->next) {
        //     ++cnt;
        //     printf("%d ", i->age);
        // }
        // printf("\n");
    }
    return arr[0];
}
#endif

