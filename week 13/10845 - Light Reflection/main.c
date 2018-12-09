#include <stdio.h>
int h, w;
int map[100][100];
int pr, pc;
int isfirst;
void light(int r, int c, int dir)
{

    if ((r==1||r==h||c==1||c==w)&&isfirst!=1) {
        pr = r;
        pc = c;
        return;
    }
    else {
        isfirst = 0;
        if (dir==0) light(r-1, c+1, dir);
        else if (dir==1) light(r+1, c+1, dir);
        else if (dir==2) light(r+1, c-1, dir);
        else if (dir==3) light(r-1, c-1, dir);
    }

}
int main()
{

    int k, i;
    int orir, oric;
    scanf("%d%d%d%d%d",&h, &w, &orir,&oric, &k);
    isfirst = 1;
    light(orir, oric, 0);
    if ((pr==h||pr==1)&&(pc==w||pc==1)) printf("(%d,%d)", pr, pc);
    for (i=1; i<k-1; i++) {
        isfirst = 1;
        light(pr, pc, i%4);
        if ((pr==h||pr==1)&&(pc==w||pc==1)) break;
    }
    printf("(%d,%d)", pr, pc);
}
