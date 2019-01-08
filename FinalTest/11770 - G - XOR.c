#include <stdio.h>
int num[100010];
int k_digit[25];
int main()
{
    int n, i, j;
    int tmp = 0;
    long long int k = 0L;
    long long int sum = 0L;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    for (i=0; i<20; i++) {
        for (j=0; j<n; j++) {
            if (((1<<i)&num[j])!=0) tmp+=1;
        }
        if (tmp>(n/2)) k_digit[i] = 1;
        else k_digit[i] = 0;
        tmp = 0;
    }

    for (i=0; i<20; i++) {
        k += k_digit[i]<<i;
    }

    for (i=0; i<n; i++) {
        sum+= k ^ num[i];
    }

    printf("%lld\n", sum);

}
