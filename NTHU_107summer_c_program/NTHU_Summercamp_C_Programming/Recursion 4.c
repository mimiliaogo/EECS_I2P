/*

power(n,p)

power(2.0, 4)
2.0 =
2.0 4
*/
#include<stdio.h>

double power(double, unsigned int);
int main(void)
{
    double n;
    unsigned p;
    scanf("%lf%d", &n, &p);
    printf("%f\n", power(n,p));
    return 0;
}

double power(double n, unsigned int p)
{
    double ans;
    if(p==0) return 1;
    ans = power(n, p/2);
    if(p%2==0)
        return ans*ans;
    else
        return ans*ans*n;
}

