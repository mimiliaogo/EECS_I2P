#include <stdio.h>
int main()
{
    char ac[1005], bc[1005];
    int a[1005], b[1005], add[1005];
    int times, size, carry, div;
    int i, j, k;
    int ans, remainder;
    k = 1;
    scanf("%d", &times);
    while (k<=times) {
        scanf("%s", ac);
        scanf("%s", bc);
        scanf("%d", &div);
        i = 0;
        while (ac[i]!='\0') {
            a[i] = ac[i] - '0';
            b[i] = bc[i] - '0';
            i++;
        }
        size = i;
        carry = 0;
        for (i=0; i<size; i++) {
            add[i] = carry + a[size-i-1] + b[size-i-1];
            carry = add[i] / 10;
            add[i]%=10;
        }
        if (carry>0) {
            size+=1;
            add[size-1] = carry;
        }


        remainder = add[size-1];
        i = size - 1;
        ans = remainder / div;
        i-=1;
        /* eat the padding */
        while (ans==0&&i>=0) {
            remainder = 10 * (remainder-ans*div) + add[i];
            ans = remainder / div;
            i--;
        }
        printf("%d", ans);
        for ( ;i>=0; i--) {
            remainder = 10 * (remainder-ans*div) + add[i];
            ans = remainder / div;
            printf("%d", ans);
        }
        printf("\n");
        k++;
    }
}
