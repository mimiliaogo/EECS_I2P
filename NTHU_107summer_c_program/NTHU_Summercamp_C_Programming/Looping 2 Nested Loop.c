#include<stdio.h>

int main(void){
    int i,j;
    for(i = 1; i <= 9; i++){
        for(j = 1; j <= 9; j++){
            printf("%3d",i*j);
        }
        printf("\n");
    }

    for(i = 1; i <= 9; i++){
        for(j = 1; j <= 9; j++){
            printf("%d*%d =%3d  ", i, j,i*j);
        }
        printf("\n");
    }

    for(i = 1; i <= 9; i++){//下半部的九九乘法
        for(j = 1; j <= i; j++){
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    printf("\n\n");

    for(i = 1; i <= 9; i++){//上半部的九九乘法
        for(j = 1; j < i; j++){
            printf("      ");
        }
        for(j = i; j <= 9; j++){
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    return 0;
}

