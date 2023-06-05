#include <stdio.h>
#include <stdlib.h>

char chess[200][200];
char target[20] = "ICPCASIASG";
int able;
int n; 
int dir[10][2] = {{2, -1}, {-2, -1}, {1, -2}, {-1, -2}, {2, 1}, {1, 2}, {-2, 1}, {-1, 2}};
void rec(int r, int c, int idx) {
    if (able) return ;
    if (idx >= 10) {
        able = 1;
        return ;
    }
    for (int i = 0; i < 8; ++i) {
        int nextr = r + dir[i][0];
        int nextc = c + dir[i][1];
        if (nextr >= 0 && nextr < n && nextc >= 0 && nextc < n && chess[nextr][nextc] == target[idx]) {
            rec(nextr, nextc, idx+1);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("\n%c", &chess[i][0]);
        for (int j = 1; j < n; ++j) {
            scanf("%c", &chess[i][j]);
        }
    }
    
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", chess[i][j]);
        }
        printf("\n");
    }*/
    able = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (chess[i][j] == 'I') {
                rec(i, j, 1);
            }
        }
    }
    printf("%s\n", (able ? "YES" : "NO"));
    return 0;
}
