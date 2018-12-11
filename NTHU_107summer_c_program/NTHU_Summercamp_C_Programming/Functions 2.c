/*

0000 0
0001 1
0010 2
0011 3
0100 4
.
.
*/
#include<stdio.h>

int pow2(int n);
void show_binary(int x, int limit);


int main(void){
    int n,i;
    int limit;
    printf("Enter the number of bits: ");
    scanf("%d", &n);

    limit = pow2(n);
    printf("%d\n", limit);

    for(i=0; i<limit; i++){
        show_binary(i,limit);
        printf(":  %d\n", i);
    }
    return 0;
}

int pow2(int n)
{
    int ans = 1;

    while(n>0){
        ans = ans*2;
        n--;
    }
    return ans;
}

void show_binary(int x, int limit) //limit = 16;
{
    limit = limit / 2;
    while(limit>0){
        printf("%d", x/limit);
        x = x % limit;
        limit = limit / 2;

    }





    /*
    1011

    1*8 + 0*4 + 1*2 + 1*1 = 11

    11/8 == 1
        11%8 == 3
    3/4 == 0
        3%4 == 3
    3/2 ==1
        3%2 == 1
    1/1 == 1
        1%1 == 0
    */


}
