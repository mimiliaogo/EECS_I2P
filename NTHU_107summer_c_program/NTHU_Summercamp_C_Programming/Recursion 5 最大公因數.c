/*
最大公因數 輾轉相除法

x   y
105 63
105%63 42
-------------
y  x%y
63 42
63%42  21
-------------
42 21
42%21  0

*/

#include<stdio.h>
int gcd(int, int);

int main(void)
{
    int x,y;
    scanf("%d%d", &x, &y);
    printf("%d", gcd(x,y));
}

int gcd(int x, int y)
{
    int ans;

    if(x%y == 0)
        ans = y;
    else
        ans = gcd(y, x%y);

    return ans;
}







