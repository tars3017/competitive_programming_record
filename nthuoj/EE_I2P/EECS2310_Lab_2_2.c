#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; 
    scanf("%d", &x);
    int yes = 1;
    if (x % 4 == 0) {
        if (x % 100 == 0 && x % 400 != 0) {
            yes = 0;
        }
    }
    else {
        yes = 0; 
    }
    if (yes) {
        printf("a leap year\n");
    }
    else {
        printf("not a leap year\n");
    }
    return 0;
}
