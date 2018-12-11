#include<stdio.h>
#define NBIN 10
#define STARS "**********************"

int main(void)
{
    int hist[NBIN] = {3,5,2,1,8,3,1,5,4,3};
    //若初始化只做一半其他自動變0
    int i;

    for(i = 0 ;i<NBIN; i++){
        printf("[%d]: %d ", i,hist[i]);
        printf("%.*s\n",hist[i], STARS);
    }
    printf("\n\n");


    int mist[] = {3,5,2,1,8,3,1,5,4,3};
    printf("mist:%u bytes\n",sizeof(mist));

    int j;

    for(j = 0 ;j<sizeof(mist)/sizeof(int);j++){
        printf("[%d]: %d ", j,mist[j]);
        printf("%.*s\n",mist[j], STARS);
    }


    return 0;
}
