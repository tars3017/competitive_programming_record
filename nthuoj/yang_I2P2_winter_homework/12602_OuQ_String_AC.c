#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// notice r over len[k] && r < l
char str[100005];
char base[5] = "OuQ";
int idx;
long long len[100];
void rec(int k, long long l, long long r) {
    if (r >= len[k]) r = len[k]-1;
    if (r < l) return ;
    if (k == 1) {
        for (int i = l; i <= r; ++i) {
            str[idx] = base[i];
            ++idx;
        }
        return ;
    }
    int get_Q = 0, get_u = 0;
    if (l == 0) {
        str[idx] = 'O';
        ++idx;
        ++l;
    }
    if (r == len[k]-1) {
        get_Q = 1;
        --r;
    }
    long long mid = len[k] / 2;
    if (l == mid) {
        str[idx] = 'u';
        ++idx;
        ++l;
    }
    if (r == mid) {
        get_u = 1;
        --r;
    }

    if (r < mid) {
        rec(k-1, l-1, r-1);    
    }
    else if (l > mid) {
        rec(k-1, l-mid-1, r-mid-1);
    }
    else if (l < mid && r > mid) {
        rec(k-1, l-1, mid-1-1);
        str[idx] = 'u';
        ++idx;
        rec(k-1, 0, r-mid-1);
    }
    else {
        assert(0);
    }
    if (get_Q) {
        str[idx] = 'Q';
        ++idx;
    }
    if (get_u) {
        str[idx] = 'u';
        ++idx;
    }
}
int main() {
    long long k, l, r;
    len[1] = 3;
    for (int i = 2; i <= 70; ++i) {
        len[i] = len[i-1] * 2 + 3;
        // printf("%lld\n", len[i]);
    }
    while (scanf("%lld %lld %lld", &k, &l, &r) == 3) {
        assert(r-l+1 <= 10000);
        memset(str, 0, sizeof(str)); 
        idx = 0;
        rec(k, l, r);
        for (int i = 0; i < r-l+1; ++i) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}
