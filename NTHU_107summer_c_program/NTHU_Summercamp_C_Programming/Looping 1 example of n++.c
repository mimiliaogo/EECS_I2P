#include<stdio.h>

int main(){
    int n = 1;
    while(n <= 3){
        printf("n = %d\n",n);
        ++n;
        printf("now n = %d\n",n);
    }
    printf("The loop is done.\n");
}
