/*
6
6*5*4*3*2*1 = 720

6! = 6*5!
5! = 5*4!
.
2! = 2*1!
1! = 1


*/
#include<stdio.h>
int fact(int );
int fact_r(int, int);

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d! = %d\n", n, fact(n));

    printf("%d! = %d\n", n, fact_r(n, 1));

    return 0;



}

int fact(int n)
{
    int ans = 1;

    while(n>0){
        ans = ans*n;
        n--;
    }
    return ans;
}




int fact_r(int n, int ans)
{


    if(n==1) {
        return ans;
    }else{
        printf("fact_r(%d, %d)\n", n-1, n*ans);
        return fact_r(n-1, n*ans);
    }

    printf("fact_r(%d) = %d\n", n, ans);
    return ans;
}
