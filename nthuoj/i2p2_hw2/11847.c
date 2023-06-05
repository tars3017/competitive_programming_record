#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ques[35];
int a, b, c, d, ans;
int idx;
int cal() {
    if (ques[idx] == '\0') return 0;
    if (ques[idx] == '|') {
        ++idx;
        int next_first = cal();
        int next_second = cal();
        // printf("%d | %d\n", next_first, next_second);
        return next_first | next_second;
    }
    else if (ques[idx] == '&') {
        ++idx;
        int next_first = cal();
        int next_second = cal();
        // printf("%d & %d\n", next_first, next_second);
        return next_first & next_second;
    }
    else {
        int val;
        if (ques[idx] == 'A') val = a;
        else if (ques[idx] == 'B') val = b;
        else if (ques[idx] == 'C') val = c;
        else if (ques[idx] == 'D') val = d;
        ++idx;
        return val;
    }
}
int main() {
    scanf("%s", ques);
    ans = 0;
    for (int i = 0; i < 16; ++i) {
        d = (i>>0) & 1;
        c = (i>>1) & 1;
        b = (i>>2) & 1;
        a = (i>>3) & 1;
        idx = 0;
        printf("%d %d %d %d ", a, b, c, d);
        printf("%d\n", cal(0));
    }
    return 0;
}
