#include <stdio.h>
char map[1005][1005];
int m, n;
int isalive = 0;
void water(int r, int c);
int main()
{
    int i,j;
    int isfinde = 0;
    int er, ec;
    scanf("%d%d", &m, &n);
    for (i=0; i<m; i++) {
        scanf("%s", &map[i]);
    }
    for (i=0; i<m&&isfinde==0; i++) {
        for (j=0; j<n&&isfinde==0; j++) {
            if (map[i][j]=='e') {
                er = i;
                ec = j;
                isfinde = 1;
            }
        }
    }
    water(er, ec);
    if (isalive==1) printf("Alive!\n");
    else printf("Dead!\n");
}
void water(int r, int c)
{
    if (r>=0&&c>=0&&r<m&&c<n&&isalive!=1) {
        if (map[r][c]=='~') {
            isalive = 1;
        }
        else if (map[r][c]!='^'){
            map[r][c]='^';
            water(r+1, c);
            water(r-1, c);
            water(r, c+1);
            water(r, c-1);
        }



    }

}
