#include<stdio.h>
#define STARS "**********************"
#define MAXBIN 25
/*�Y�n���ɮ׾ɦV�A�Ьݼv��*/
int main(void)
{
    int hist[MAXBIN];
    int i,nbin;

    for(nbin=0; nbin<MAXBIN;nbin++){
        if(scanf("%d", &hist[nbin]) != 1)
            break;
    }

    for(i = 0 ;i<nbin; i++){
        printf("[%d]: %d ", i,hist[i]);
        printf("%.*s\n",hist[i], STARS);
    }
}
