#include<stdio.h>
#include<stdlib.h>

int main(void)
{

    int * a;
    int rows, cols;
    int * * b;
    int i,j;

    scanf("%d%d", &rows, &cols);//列＆行

    a = (int *)malloc( rows*cols * sizeof(int));

    for(i=0; i<rows*cols; i++) a[i] = i;

    b = (int * *)malloc( rows* sizeof(int *) );//指標都是４　ｂｙｔｅｓ
    /* illustrations in the clip */

    for(i=0; i<rows; i++) b[i] = &a[i*cols];

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("%3d ", b[i][j]);//偏移量
        }
        printf("\n");
    }
    free(b);
    free(a);


    return 0;





}
