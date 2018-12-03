#include <stdio.h>
int map[25][25];
int fl, ce, h, s;
int maxcol()
{
    int i=0;
    while (1)
    {
        if (map[0][i]==1) return i+1;
        else if (map[h+1][i]==1) return i+1;
        i++;
    }
}
void show()
{
    int i, j;
    int maxcolume = maxcol();
//    int maxcolume =  25;
    for (i=0; i<h+2; i++) {
        for (j=0; j<maxcolume; j++) {
            if (map[i][j]==0) printf(" ");
            else if (map[i][j]==1) printf("*");
            else printf("-");
        }
        printf("\n");
    }
}

int main()
{

    char dir;
    int i;
    scanf("%d%d%d%d", &ce, &fl, &h, &s);
    while ((dir=getchar())==' ');
    for (i=0; i<ce; i++) {
        map[0][i] = 2;
    }
    for (i=0; i<fl; i++) {
        map[h+1][i] = 2;
    }
    draw(s, 0, dir);
    show();
    return 0;

}
void draw(int r,int c, char dir)
{
    map[r][c]=1;
    if ((r==0)||(r==h+1)) return;
    if (dir=='u'&&map[r-1][c]==2) {
        dir = 'd';
//        draw(r, c, dir);
    }
    else if (dir=='d'&&map[r+1][c]==2) {
        dir = 'u';
//        draw(r, c, dir);
    }
    if (dir=='u') {
        draw(r-1, c+1, dir);
    }
    else if (dir=='d') {
        draw(r+1, c+1, dir);
    }

}
