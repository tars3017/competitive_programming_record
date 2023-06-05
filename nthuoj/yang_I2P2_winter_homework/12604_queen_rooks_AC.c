#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// notice rook_s, rook_bs and the range is bieeger
int col[30];
int slash[30], bslash[30];
int rook_s[30], rook_bs[30];
long long ans;
int total;
void rec(int n, int m, int now_col) {
    if (n == 0 && m == 0) ++ans;
    if (n > 0) {
        for (int i = 0; i < total; ++i) {
            int slash_v = now_col + i;
            int bslash_v = i - now_col + 10; 
            if (!col[i] && !slash[slash_v] && !bslash[bslash_v] &&
                !rook_s[slash_v] && !rook_bs[bslash_v]) {
                col[i] = 1;
                slash[slash_v] = 1;
                bslash[bslash_v] = 1;
                rook_s[slash_v] = 1;
                rook_bs[bslash_v] = 1;
                rec(n-1, m, now_col+1);
                col[i] = 0;
                slash[slash_v] = 0;
                bslash[bslash_v] = 0;
                rook_s[slash_v] = 0;
                rook_bs[bslash_v] = 0;
            }
        }
    }
    if (m > 0) {
        for (int i = 0; i < total; ++i) {
            int slash_v = now_col + i;
            int bslash_v = i - now_col + 10; 
            int origin_s = rook_s[slash_v];
            int origin_bs = rook_bs[bslash_v];
            if (!col[i] && !slash[slash_v] && !bslash[bslash_v]) {
                col[i] = 1;
                rook_s[slash_v] = 1;
                rook_bs[bslash_v] = 1;
                rec(n, m-1, now_col+1);
                col[i] = 0;
                rook_s[slash_v] = origin_s;
                rook_bs[bslash_v] = origin_bs;
            }
        }
    }
}
int  main() {
    int n, m;
    while( scanf("%d %d", &n, &m) == 2) {
        memset(col, 0, sizeof(col));
        memset(slash, 0, sizeof(slash));
        memset(bslash, 0, sizeof(bslash));
        memset(rook_s, 0, sizeof(rook_s));
        memset(rook_bs, 0, sizeof(rook_bs));
        ans = 0;
        total = n + m;
        rec(n, m, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
