#include <stdio.h>
#include <stdlib.h>

int c[10000], a[10000];
int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", c+i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", a+i);
    }
    int idx = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i] <= a[idx]) {
            ++cnt;
            ++idx;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
