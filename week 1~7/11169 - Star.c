#include <stdio.h>
int main ()
{
    char s[50][50];
    int m, n;
    int i,j;
    int x, y;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y);
    /* star = '-' */
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            s[i][j] = '-';
        }
    }

    /* diagonal line = '*' */
    i = 0;
    for (j=y-x;j<m;j++) {
         if (i<n) {
            if (j>=0) s[i][j] = '*';
        }
    i++;
    }

    i = 0;
    for (j=y+x;j>=0;j--) {
        if (i<n) {
            if (j<=m) s[i][j] = '*';
        }
    i++;
    }
    /* x rows y columns = '+' */
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (i==x||j==y) {
                s[i][j] = '+';
            }
        }
    }
    /* center */
    s[x][y] = 'S';
    /* print star */
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }




}
