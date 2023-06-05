#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b ? a : b);
}
int max(int a, int b) {
    return (a > b ? a : b);
}
int main() {
    int n; scanf("%d", &n);
    int home;
    scanf("%d", &home);
    int num, min_v = 0x3f3f3f3f, max_v = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        min_v = min(min_v, num);
        max_v = max(max_v, num);
    }
    long long ans = 0;
    if (max_v > home && min_v > home) {
        ans = (max_v-home) * 2;
    }
    else if (max_v > home && min_v < home) {
        ans = (max_v - home + home - min_v) * 2;
    }
    else if (max_v < home) {
        ans = (home-min_v) * 2;
    }
    printf("%lld\n", ans);
    return 0;
}
