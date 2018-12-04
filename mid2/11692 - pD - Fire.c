#include <stdio.h>
char map[1010][1010];
int m, n;
int alive;
void water(int r, int c);
int main()
{

    int i, j, erow, ecol;
    scanf("%d%d", &m, &n);
    for (i=0; i<m; i++) {
        scanf("%s", &map[i]);
    }
    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            if (map[i][j]=='e') {
                erow = i;
                ecol = j;
            }
        }
    }
    water(erow, ecol);
    if (alive) printf("Alive!");
    else printf("Dead!");
    return 0;

}
void water(int r, int c)
{
    if (r>=0&&r<m&&c>=0&&c<n) {
        if (map[r][c]=='~') {
            alive = 1;
            return;
        }
        else if (map[r][c]!='^') {
            map[r][c] = '^';
            water(r+1, c);
            water(r-1, c);
            water(r, c+1);
            water(r, c-1);
        }
    }
}
