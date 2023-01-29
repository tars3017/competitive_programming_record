#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[200];
int main() {
    int k, l, r;
    scanf("%d %d %d", &k, &l, &r);
    arr[0] = 1, arr[1] = 2, arr[3] = 3;
    rec(1, 0, 3);
    return 0;
}
