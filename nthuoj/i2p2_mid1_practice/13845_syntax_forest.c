#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct _Node {
    char data;
    struct _Node *left, *right;
}Node;


long long fixed_val[10];
Node* my_func[50];

Node* create_node(char ch) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = ch;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* build_tree() {
    char now_ch;
    scanf("%c", &now_ch);
    // printf("now_ch = %c\n", now_ch);

    if ( (now_ch >= 'A' && now_ch <= 'D') || (now_ch == 'X') || (now_ch >= 'a' && now_ch <= 'z') ) {
        return create_node(now_ch);
    }
    else {
        // printf("here\n");
        Node* now = create_node(now_ch);
        now->left = build_tree();
        now->right = build_tree();
        return now;
    }
}

long long Mod(long long num){
    num %= 998244353;
    if(num < 0) num += 998244353;
    return num;
}
long long eval(Node* now, long long param) {
    char data = now->data;
    long long ret;
    long long f_ans = 0, s_ans = 0;
    if (data >= 'A' && data <= 'D') {
        ret = Mod(fixed_val[data-'A']); 
    }
    else if (data == 'X') {
        ret = param; 
    }
    else if (data == '+') {
        f_ans = eval(now->left, param);
        s_ans = eval(now->right, param);

        ret = Mod(f_ans + s_ans);
    }
    else if (data == '-') {
        f_ans = eval(now->left, param);
        s_ans = eval(now->right, param);

        f_ans = Mod(f_ans);
        s_ans = Mod(s_ans);
        ret = Mod(f_ans - s_ans);
    }
    else if (data == '*') {
        f_ans = eval(now->left, param);
        s_ans = eval(now->right, param);

        ret = Mod(f_ans * s_ans);
    }
    else if (data == '@') {
        char call_next = now->left->data; 

        s_ans = eval(now->right, param);
        s_ans = Mod(s_ans);

        ret = eval(my_func[call_next-'a'], s_ans); 
    }
    else {
        assert(0);
    }

    return Mod(ret);
}
int main() {
    int n, q;
    scanf("%d %d\n", &n, &q);
    // printf("n=%d %d\n", n, q);
    for (int i = 0; i < n; ++i) {
        char func_name;
        scanf("\n%c ", &func_name);
        // printf("%c read all func\n", func_name);
        my_func[func_name-'a'] = build_tree();
    }
    for (int i = 0; i < q; ++i) {
        char call_func;
        long long x;
        scanf("\n%c ", &call_func);
        scanf("%lld %lld %lld %lld %lld", &x, &fixed_val[0], &fixed_val[1], &fixed_val[2], &fixed_val[3]); 
        
        printf("%lld\n", eval(my_func[call_func-'a'], x));
    }
    return 0;
}
