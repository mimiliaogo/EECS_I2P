//改寫自1
#include<stdio.h>
int sum(int * startp, int * endp);

int main()
{
    int a[10] = {1,1,2,3,5,8,13,21,34,55};
    int total;

    total = sum(a, a+10);
    printf("%p %p\n", a, a+10);
    printf("total: %d\n", total);
    return 0;
}

int sum(int * startp, int * endp)
{
    int ans = 0;
    printf("endp: %p\n", endp );
    printf("startp: ");
    while(startp<endp){
        printf("%p ", startp);
        ans = ans + *startp;
        startp++;
    }
    printf("\n");


    return ans;
}
