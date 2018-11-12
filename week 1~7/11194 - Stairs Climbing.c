#include<stdio.h>
int stair(int num);
int main()
{
    int num;
    int k;
    scanf("%d", &k);
    while (k>0) {
        scanf("%d", &num);
        printf("%d\n", stair(num));
        k--;

    }
    return 0;
}
int stair(int n)
{
    if (n==1) return 1;
    else if (n==2) return 2;
    else {
        return stair(n-1) + stair(n-2);
    }
}
