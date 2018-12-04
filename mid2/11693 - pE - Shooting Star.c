#include <stdio.h>
int h,fl,ce;
int map[50][50];
int maxstar()
{
    int i;
    for (i=0; ; i++) {
        if (map[0][i]==1||map[h+1][i]==1) return i+1;
    }
}
void display()
{
    int i ,j;
    int maxstars = maxstar();

    if (maxstars<fl) maxstars = fl;
    if (maxstars<ce) maxstars = ce;

    for (i=0; i<h+2; i++) {
        for (j=0; j<maxstars; j++) {
            if (map[i][j]==1) printf("*");
            else if (map[i][j]==2) printf("-");
            else printf(" ");
        }
        printf("\n");
    }

}
void draw(int r, int c, char dir)
{
    map[r][c] = 1;
    if (r==0||r==h+1) return;
    if (map[r-1][c]==2&&dir=='u') {
        dir = 'd';
    }
    else if (map[r+1][c]==2&&dir=='d') {
        dir = 'u';
    }

    if (dir=='u') {
        draw(r-1, c+1, 'u');
    }
    else if (dir=='d') {
        draw(r+1, c+1, 'd');
    }
}
int main()
{
    int s, i, j;
    char dir;
    scanf("%d%d%d%d", &ce, &fl, &h, &s);
    scanf("%c", &dir);
    scanf("%c", &dir);
    for (i=0; i<ce; i++) map[0][i] = 2;
    for (i=0; i<fl; i++) map[h+1][i] = 2;

    draw(s, 0, dir);
    display();
    return 0;

}
