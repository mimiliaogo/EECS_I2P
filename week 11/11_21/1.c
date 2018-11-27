/*two variables have diff memory address
using macro to show which function it is in*/
#include <stdio.h>
void f(int x);
int main()
{
    int x;
    scanf("%d", &x);
    f(x);
    printf("%s: %p\n", __func__, &x);
    printf("%d\n", x);
}

void f(int x)
{
    printf("%s: %p\n", __func__, &x);
    x = x+1;
}
