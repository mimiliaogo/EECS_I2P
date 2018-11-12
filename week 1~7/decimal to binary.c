#include <stdio.h>
void dec2bin(int n, int div);
int main()
{
    int n;
    int div;
    while (scanf("%d%d", &n, &div)==2) {
        dec2bin(n,div);
        printf("\n");
    }


    return 0;
}

void dec2bin(int n, int div)
{
    int ans;
    if (n>0) {
        dec2bin(n/div, div);
        printf("%d", n%div);
    }
    return ans;

}
