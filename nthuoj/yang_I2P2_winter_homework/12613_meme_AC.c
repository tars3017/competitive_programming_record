#include <stdio.h>
#include <stdlib.h>

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        long long a, b;
        scanf("\n%lld %lld", &a, &b);
        long long now = 1;
        int cnt = 0;
        for (int i = 1; i <= 9; ++i) {
            now *= 10;
            if (b >= now-1) ++cnt;     
        }
        printf("%lld\n", cnt*a);
    }
    return 0;
}
