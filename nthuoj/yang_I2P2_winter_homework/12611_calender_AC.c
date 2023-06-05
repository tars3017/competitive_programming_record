#include <stdio.h>
#include <stdlib.h>

int is_leap(int x) {
    if (x % 4 == 0) {
        if (x % 100 == 0) {
            if (x % 400 == 0) return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}
int main() {
    int t; 
    scanf("%d", &t);
    while (t--) {
        int y; scanf("\n%d", &y);
        int origin_leap = is_leap(y);
        int day_pass = 0;
        while (1) {
            day_pass += (is_leap(y) ? 366 : 365);
            day_pass %= 7;
            ++y;
            if (day_pass == 0 && is_leap(y) == origin_leap) {
                printf("%d\n", y);
                break;
            }
        }
    }
    return 0;
}
