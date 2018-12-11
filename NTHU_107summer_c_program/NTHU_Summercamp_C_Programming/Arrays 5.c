#include<stdio.h>

int main(void)
{
    int a[][4] = {{1,2,3,4}, {5,6}, {9,10,11,12} };
    int b[][4] = {1,2,3,4,5,6,9,10,11,12};

    int i,j;

    printf("a:       %d bytes\n", sizeof(a));// 12 個整數
    printf("a[0]:    %d bytes\n", sizeof(a[0]));// 第一列
    printf("a[0][0]: %d bytes\n", sizeof(a[0][0]));//一個整數
    printf("\n");


    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<3; i++){
        for(j=0; j<4; j++){
            printf("%3d",b[i][j]);
        }
        printf("\n");
    }
}
