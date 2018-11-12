#include <stdio.h>
int main()
{
    int bit[30];
    int n;
    int i=0;
    int carry = 0;
    scanf("%d", &n);
    n = n+1;
    while (n>0) {
        bit[i] = n%2;
        n/=2;
        i++;
    }
    n = i;
    for (i = i-1; i>=0; i--) {
        printf("%d", bit[i]);
    }
    i=0;
    while (i<n&&bit[i]==0) {
        carry++;
        i++;
    }
    printf(" %d", carry);
    return 0;
}
