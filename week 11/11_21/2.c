/*傳進位址拿鑰匙改裡面的東西*/
#include <stdio.h>
void f(int *);
int main()
{
    int x;
    scanf("%d", &x);
    f(&x);

    printf("%d\n", x);
    return 0;
}

void f(int * xp)
{
    *xp = *xp + 1; /*enter the room*/
}

