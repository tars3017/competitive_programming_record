#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; 
    scanf("%d", &n);
    int i;
    for (i = 1; i <= n; ++i) {
        int j;
        for (j = 1; j <= i; ++j) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}
