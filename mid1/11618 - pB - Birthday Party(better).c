#include <stdio.h>
long long  icm(long long  x, long long  y);
long long  gcd(long long  x, long long  y);
int main()
{

    int t;
    long long  total;
    long long  x1, x2, x3;
    long long  bal3;//隔幾個給三個氣球
    scanf("%d", &t);
    while (t>0) {
        scanf("%lld", &total);
        scanf("%lld%lld%lld", &x1, &x2, &x3);
        x1 = gcd(total, x1);
        x2 = gcd(total, x2);
        x3 = gcd(total, x3);
        bal3 = icm(x1, x2);
        bal3 = icm(bal3, x3);
        printf("%lld\n", total/bal3);
        t--;
    }



}

long long  icm(long long  x, long long  y)
{
    return x/gcd(x, y)*y;
}

long long  gcd(long long  x, long long  y)
{
    long long  ans;
    if (x%y==0) ans = y;
    else ans = gcd(y, x%y);
    return ans;
}
