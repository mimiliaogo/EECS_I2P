#include <stdio.h>
int num[100005];
int ks[25];
int main()
{
    int n, i, temp=0, j;
    long long int k = 0L;
    long long int sum = 0L;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    //run through all the digits and judge 1 or 0 is more
    for (i=0; i<20; i++) {
        for (j=0; j<n; j++) {
            if (((1<<i)&num[j])!=0) temp += 1;
            if (temp>(n/2)) ks[i] = 1;
            else ks[i] = 0;
        }
        temp = 0;
    }

    for (i=0; i<20; i++) {
        k += ks[i]<<i;
    }
    for (i=0; i<n; i++) {
        sum+= k ^ num[i];
    }
    printf("%lld\n", sum);
}
