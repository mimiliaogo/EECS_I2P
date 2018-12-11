#include<stdio.h>
int gcd(int, int);
int main(void)
{
    int x,y;
    scanf("%d%d",&x, &y);

    printf("(%d,%d) gcd = %d",x,y,gcd(x, y));

}

int gcd(int a, int b)
{
    int ans;
    if(a%b==0)
        ans = b;
    else
        ans = gcd(b, a%b);
    return ans;
}


