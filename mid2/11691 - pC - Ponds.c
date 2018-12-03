//important for test
#include <stdio.h>
char map[1005][1005];
void pond(int x, int y);
int m, n;
int main()
{
    int i, j;
    int count = 0;
    scanf("%d%d", &m, &n);
    for (i=0; i<m; i++) {
        scanf("%s", map[i]);
    }
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            if (map[i][j]=='~') {
                pond(i, j);
                count++;
            }
        }

    }
    printf("%d\n", count);

}

void pond(int x, int y)
{
   if (map[x][y]=='~'&&x>=0&&y>=0&&x<m&&y<n) {
        map[x][y] = '0';
        pond(x-1, y);
        pond(x+1, y);
        pond(x, y+1);
        pond(x, y-1);
   }

}
