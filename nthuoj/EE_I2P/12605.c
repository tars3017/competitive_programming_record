#include <stdio.h>
#include <stdlib.h>

char str[200005];
int trans1[200005];
int trans2[200005];
int main() {
    int n, m;
    scanf("%d %d%*c", &n, &m);
    scanf("%s%*c", str);
    for (int i = 0; i <= 26; ++i) {
        trans1[i] = i;
        trans2[i] = i;
    }
    /* printf("str=%s\n", str); */
    while (m--) {
        char a, b;
        scanf("%c %c%*c", &a, &b);
        int to_b = 0, to_a = 0;
        for (int i = 0; i < 26; ++i) {
            if (trans1[i] == a-'a') {
                to_b = i; 
            }
            if (trans1[i] == b-'a') {
                to_a = i;
            }
        }
        trans1[to_b] = b-'a';
        trans1[to_a] = a-'a';
    }
    for (int i = 0; i < n; ++i) {
        str[i] = trans1[str[i]-'a']+'a';
    }
    printf("%s\n", str);
    return 0;
}
