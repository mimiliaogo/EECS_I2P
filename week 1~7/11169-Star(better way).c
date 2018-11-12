#include <stdio.h>

int main()
{
    int n, m;
    int i, j;
    int x, y;
    char map[20][20];
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y);
    //set up the map
    for (i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            map[i][j] = '-';
        }
    }

    //diagonal
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if ((i-x) == (j-y)||(i-x) == -(j-y)) {
                map[i][j] = '*';
            }
        }
    }
    // x,y rows

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (i==x||j==y) {
                map[i][j] = '+';
            }
        }
    }
    //center
    map[x][y] = 'S';
    //show
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

