#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int row[25], col[25], slash[25], bslash[25], castle_sl[25], castle_bs[25];;
int leng, cnt;
void rec(int x, int y, int now) {
    if (now > leng) {
        if (x == 0 && y == 0) {
            /* printf("end\n"); */
            cnt++;
        }
        return ;
    }
    if (x > 0) {
        for (int j = 1; j <= leng; ++j) {
            if (col[j]) continue;
            else if (slash[now+j]) continue;
            else if (bslash[now-j+10]) continue;
            else if (castle_sl[now+j]) continue;
            else if (castle_bs[now-j+10]) continue;
            col[j] = 1;
            slash[now+j] = 1;
            bslash[now-j+10] = 1;
            /* printf("Q %d %d\n", now, j); */
            rec(x-1, y, now+1);
            col[j] = 0, slash[now+j] = 0, bslash[now-j+10] = 0;
        }
    }
    if (y > 0) {
        for (int j = 1; j <= leng; ++j) {
            if (col[j]) continue;
            else if (slash[now+j]) continue;
            else if (bslash[now-j+10]) continue;
            int origin_a = castle_sl[now+j], origin_b = castle_bs[now-j+10];
            col[j] = 1;
            castle_sl[now+j] = 1;
            castle_bs[now-j+10] = 1;
            /* slash[now+j] = 1; */
            /* bslash[now-j+10] = 1; */
            /* printf("R %d %d\n", now, j); */
            rec(x, y-1, now+1);
            col[j] = 0;
            castle_sl[now+j] = origin_a, castle_bs[now-j+10] = origin_b;
        }
    }
}
int main() {
    int n, m; 
    while (scanf("%d %d", &n, &m) != EOF) {
        /* memset(row, 0, sizeof(row)); */
        memset(col, 0, sizeof(col));
        memset(slash, 0, sizeof(slash));
        memset(bslash, 0, sizeof(bslash));
        memset(castle_sl, 0, sizeof(castle_sl));
        memset(castle_bs, 0, sizeof(castle_bs));
        cnt = 0;
        leng = n+m;
        rec(n, m, 1);
        printf("%d\n", cnt);
    }
    return 0;
}
