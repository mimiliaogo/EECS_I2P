#include<stdio.h>
// 質因數分解
int main(void){

    unsigned int num, div;
    int isPrime;

    printf("Enter an integer(q to quit): ");
    while(scanf("%u", &num)==1){
        isPrime = 1;
        for(div=2; div*div<=num; div++){
            if(num%div == 0){
                if(num == div*div){
                    printf("%u, ", div);
                }else{
                    printf("%u, %u, ", div, num/div);
                }
                isPrime = 0;
            }
        }
        if(isPrime == 1){
            printf("%u is a prime number.\n", num);
        }else{
            printf("\b\b are divisors of %u.\n", num);
        }


        printf("\nEnter another integer(q to quit): ");



    }




}
