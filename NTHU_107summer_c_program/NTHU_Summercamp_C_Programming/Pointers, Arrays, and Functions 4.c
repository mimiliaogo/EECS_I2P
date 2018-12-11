/*important! suggest to do it yourself*/
#include<stdio.h>
void permute(char a[], int n);
void swap(char * x, char * y);
int main()
{
    char a[] = {'a', 'b', 'c', 'd', '\0'};//反斜線0使得可當字串使用 also can be "abcd"

    //printf("%s\n", a);

    permute(a, 4);

    return 0;
}

void permute(char a[], int n)
{
    int i;
    if(n==1){
        printf("%s\n", a);
    }
    else
    {
        for(i=n-1; i>=0; i--){
            swap(&a[i], &a[n-1]);
            permute(a, n-1);
            swap(&a[i], &a[n-1]);
        }


    }

}

void swap(char * x, char * y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}
