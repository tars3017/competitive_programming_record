#include <stdlib.h>
#include <stdio.h>
typedef struct _node {
    int value;
    struct _node *left;
    struct _node *right;
} Node;

// create a new node
Node *create_node(int value) {
    Node* now = (Node*)malloc(sizeof(Node));
    now->value = value;
    now->left = NULL;
    now->right = NULL;
    return now;
}
int idx;
// verify whether the postorder is match with the input
int verify(Node *root, int *postorder) {
    if (root == NULL) return 1;
    int res1 = 0, res2 = 0;
    res1 = verify(root->left, postorder);
    res2 = verify(root->right, postorder);
    if (root->value != postorder[idx]) {
        ++idx;
        return 0;
    }
    else {
        ++idx;
        return (res1 & res2);
    }
}
int verify2(Node *root, int *preorder) {
    if (root == NULL) return 1;
    int res1 = 0, res2 = 0;
    if (root->value != preorder[idx]) {
        ++idx;
        verify2(root->left, preorder);
        verify2(root->right, preorder);
        return 0;
    }
    else {
        ++idx;
        res1 = verify2(root->left, preorder);
        res2 = verify2(root->right, preorder);
        return res1 & res2;
    }
}
// free the memory
void destroy(Node *root) {
    if (root == NULL) return ;
    Node *now_left = root->left;
    Node *now_right = root->right;
    free(root);
    destroy(now_left);
    destroy(now_right);
}
/*
    Parameter description:
    int *inorder : the inorder traversal sequence of the binary tree.
    int *preorder : the preorder traversal sequence of the binary tree.
    int inorder_start : the starting index of the inorder traversal of the subtree.
    int inroder_end : the ending index of the inorder traversal of the subtree.

    As for the preorder traversal index, you can try declaring a global variable.
*/
// build the tree using recursive
int n; 
Node *build(int *inorder, int *preorder, int inorder_start, int inorder_end) {
    // printf("%d %d %d\n", inorder_start, inorder_end, idx);
    if (inorder_start < 0 || inorder_end >= n || idx >= n || inorder_start > inorder_end) return NULL;
    else if (inorder_start == inorder_end) {
        ++idx;
        return create_node(inorder[inorder_start]);
    }
    int root_val = preorder[idx];
    // printf("now root val %d\n", root_val);
    Node* now_root = create_node(root_val);
    ++idx;
    int root_idx = inorder_start;
    for (int i = inorder_start; i <= inorder_end; ++i) {
        if (inorder[i] == root_val) {
            root_idx = i;
            break;
        }
    }
    now_root->left = build(inorder, preorder, inorder_start, root_idx-1);
    now_root->right = build(inorder, preorder, root_idx+1, inorder_end);
    return now_root;
}

int inorder[200005], preorder[200005];
int postorder[200005];
void print_tree(Node* root) {
    if (root == NULL) return ;
    printf("%d ", root->value);
    if (root->left != NULL) printf("l %d", root->left->value);
    if (root->right != NULL) printf("r %d", root->right->value);
    printf("\n");
    print_tree(root->left);
    print_tree(root->right);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &postorder[i]);
    }
    int q; scanf("%d", &q);
    while (q--) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &inorder[i]);
        }
        // printf("inorder\n");
        // for (int i = 0; i < n; ++i) {
        //     printf("%d ", inorder[i]);
        // }
        // printf("\n");
        idx = 0;
        Node* root = build(inorder, preorder, 0, n-1);
        // print_tree(root);
        idx = 0;
        int ver1 = verify(root, postorder);
        idx = 0;
        int ver2 = verify2(root, preorder);
        printf("%s\n", (ver1 & ver2) ? "Yes" : "No" );
        destroy(root);
    }

    return 0;
}
