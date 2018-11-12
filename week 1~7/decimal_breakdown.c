#include <stdio.h>
int main(void)
{
    int num;
    int dig[20];
    int i=0;
    scanf("%d", &num);
    while(num >= 10)
    {
        dig[i] = num%10;
        num/=10;
        i++;
    }
    dig[i] = num;

    for ( ;i>=0; i--) {
        printf("%d", dig[i]);
    }
    return 0;
}
