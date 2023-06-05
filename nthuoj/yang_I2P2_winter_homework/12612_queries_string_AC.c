#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[10005];
char tmp[10005];
int main() {
    scanf("%s", str);
    int m; 
    scanf("%d", &m);
    while (m--) {
        int l, r, k;
        scanf("\n%d %d %d", &l, &r, &k);
        k %= (r-l+1);
        --l, --r;
        // printf("l=%d r=%d k=%d\n", l, r, k);
        memset(tmp, 0, sizeof(tmp));
        for (int i = r-k+1, j = 0; i <= r; ++i, ++j) {
            tmp[j] = str[i]; 
        }
        for (int i = r-k; i >= l; --i) {
            str[i+k] = str[i];
        }
        for (int i = l, j = 0; i < l+k; ++i, ++j) {
            str[i] = tmp[j]; 
        }
    }
    printf("%s\n", str);
    return 0;
}
