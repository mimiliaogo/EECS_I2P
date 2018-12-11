#include<stdio.h>
int sum(int * ap, int size);
//int sum(int [], int size);等價
int main()
{
    int a[10] = {1,1,2,3,5,8,13,21,34,55};
    int total;

    total = sum(a,10);
    printf("total: %d\n", total);
    return 0;
}

int sum(int * ap, int size)
{
    int ans = 0;
    int i;
    for(i=0; i<size; i++){
        ans = ans + *(ap+i);//ap[i]
    }

    return ans;
}
