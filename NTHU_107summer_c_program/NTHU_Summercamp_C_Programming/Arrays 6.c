#include<stdio.h>
#define SIZE 4

int main(void)
{
 /*   int a[10];

    printf("%p %p\n", a, &a[0]);
    //陣列的第一個元素的記憶體位置 跟透過名稱取得的位置一樣
 */


    char cdata[SIZE] = {'A', 'M', 'C', 'D'};
    char * ptc;
    int idata[SIZE] = {1,2,3,4};
    int * pti;
    int k;
    ptc = cdata;
    pti = idata;

    for(k=0; k<SIZE; k++){
        printf("ptc+%d: %p %c    pti+%d:   %p %d\n", k,
               ptc+k, *(ptc+k), k,pti+k, *(pti+k)  );
    }
    //位置位移一格 注意對於記憶體的變化
    return 0;
}
/*
ptc+k
=&cdata[k]
*/
