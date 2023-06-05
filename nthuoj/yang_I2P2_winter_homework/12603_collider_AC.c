#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[200005];
long long arr[200005];
int main() {
    int n; scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", arr+i);
    }
    long long ans = 0x3f3f3f3f;
    for (int i = 0; i < n-1; ++i) {
        if (str[i] == 'R' && str[i+1] == 'L') {
            long long dis = arr[i+1]-arr[i];
            if (dis/2 < ans) ans = dis/2;
        }
    }
    if (ans == 0x3f3f3f3f) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}
