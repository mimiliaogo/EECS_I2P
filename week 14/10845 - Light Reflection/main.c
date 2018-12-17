#include <stdio.h>
#define UL 3
#define UR 0
#define DL 2
#define DR 1
int pr, pc, h, w;
int isfirst;
void light(int r, int c, int dir)
{
    if ((r==1||r==h||c==1||c==w)&&isfirst==0) {
        pr = r;
        pc = c;
        return;
    }else {
        isfirst = 0;
        if (dir==UL) light(r-1, c-1, dir);
        else if (dir==UR) light(r-1, c+1, dir);
        else if (dir==DL) light(r+1, c-1, dir);
        else light(r+1, c+1, dir);
    }

}
int main()
{
    int k, i;
    int dir=0;
    scanf("%d%d", &h, &w);
    scanf("%d%d", &pr, &pc);
    scanf("%d", &k);
    for (i=2; i<=k; i++) {
        isfirst = 1;
        light(pr, pc, dir);
        if (((pr==1)||(pr==h))&&((pc==1)||(pc==w))) break;
        if (dir==UR) {
            if (pr==1) dir = DR;
            else dir = UL;
        }
        else if (dir==UL) {
            if (pr==1) dir = DL;
            else dir = UR;
        }
        else if (dir==DL) {
            if (pr==h) dir = UL;
            else dir = DR;
        }
        else  if (dir==DR){
            if (pr==h) dir = UR;
            else dir = DL;
        }

    }
    printf("(%d,%d)", pr, pc);
}
