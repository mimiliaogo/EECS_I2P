#include <stdio.h>
void f(int n);

int main()
{
    int n;
    scanf("%d", &n);
    f(n);
    return 0;
}

void f(int n)
{
    if (n>0) {
        printf("(%d ", n);/*original order(before the recursion) */
        f(n-1);
        printf("%d) ", n); /*f(9)do all thing before 10 was printed
                            invert order(after the recursion */

    }
}
