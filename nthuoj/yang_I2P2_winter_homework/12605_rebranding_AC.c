#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[200005];
char table[30];
int modified[30];
int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    scanf("%s", str);
    for (int i = 0; i <= 26; ++i) {
        table[i] = i;
    }
    while (m--) {
        // printf("m=%d\n", m);
        memset(modified, 0, sizeof(modified));
        char a, b;
        scanf("\n%c %c", &a, &b);
        for (int i = 0; i < 26; ++i) {
            if (table[i] == a-'a' && !modified[i]) {
                // printf("%c to %c\n", table[i]+'a', b);
                table[i] = b-'a';
                modified[i] = 1;
            }
            if (table[i] == b-'a' && !modified[i]) {
                // printf("%c to %c\n", table[i]+'a', a);
                table[i] = a-'a';
                modified[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        str[i] = table[str[i]-'a'] + 'a';
    }
    printf("%s\n", str);
    return 0;
}
