typedef struct _Node {
    int id;
    struct _Node* next;
} Node;

void reverse(Node *node_l, Node *node_r) {
    // printf("%d %d\n", node_l->id, node_r->id);
    Node* real_head = node_l->next;
    Node* point_out = node_r->next;
    if (real_head == node_r) return ;
    Node* now = real_head->next;
    Node* prev = real_head;
    int stop = 0;
    for (; !stop; ) {
        if (now == node_r) stop = 1;
        Node* next_node = now->next;
        now->next = prev;
        prev = now;
        now = next_node;
    }
    node_l->next = node_r;
    real_head->next = point_out; 
}
