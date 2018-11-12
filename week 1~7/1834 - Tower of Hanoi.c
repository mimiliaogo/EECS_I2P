#include <stdio.h>
void hanoi(int n);
int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n);
}

void hanoi(int n)
{
    int i;
    if (n==1) printf("%d\n", n);
    else {
        hanoi(n-1);
        printf("%d\n", n);
        hanoi(n-1);
    }


}
