#include<stdio.h>

int main(void){

    int num;
    int sum = 0;
    int status;

    printf("Enter an integer(q to quit): ");
    status = scanf("%d",&num);

    while(status == 1){
          sum = sum + num;
          printf("Enter next integer(q to quit):");
          status = scanf("%d",&num);
    }
    printf("%d",sum);

}
