#include<stdio.h>

int main(void){

    int n;
    int sum;
    for(n=1, sum=0; n<10; n++){
        printf("n = %d\n",n);
        sum = sum + n;
    }
    printf("sum=%d\n",sum);

    return 0;
}
