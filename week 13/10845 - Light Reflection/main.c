#include <stdio.h>
int h, w;
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
    int dir=0;
    scanf("%d%d%d%d%d",&h, &w, &orir,&oric, &k);
    isfirst = 1;
    pr = orir;
    pc = oric;
//    light(orir, oric, dir);
//    if ((pr==h||pr==1)&&(pc==w||pc==1)) printf("(%d,%d)", pr, pc);
    for (i=2; i<=k; i++) {
        light(pr, pc, dir);
        if ((pr==h||pr==1)&&(pc==w||pc==1)) break;
        isfirst = 1;
        if (dir==0) {
            if (pr==1) dir = 1;
            else dir = 3;
        }
        else if (dir==1) {
            if (pr==h) dir = 0;
            else dir = 2;
        }
        else if (dir==2) {
            if (pr==h) dir = 3;
            else dir = 1;
        }
        else {
            if (pr==1) dir = 2;
            else dir = 0;
        }
    }
    printf("(%d,%d)", pr, pc);
}
