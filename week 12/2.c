#include <stdio.h>
int main()
{
    int arr[4] = {10, 20, 30, 40};
    int *ptr1;
    int *ptr2;

    ptr1 = arr;
    ptr2 = &arr[3];
    show(ptr1, 4);
    printf("&ptr1:%p ptr1:%p *ptr1:%d\n", &ptr1, ptr1, *ptr1);
    printf("&ptr2:%p ptr2:%p *ptr2:%d\n", &ptr2, ptr2, *ptr2);

}
void show(int a[], int n)
{
    int *ip;
    for (ip=a; ip < a+n; ip++) {
        printf("| %8p", ip);
    }
    printf(" |\n");
    for (ip=a; ip< a+n; ip++) {
        printf("| %8d", *ip);
    }
    printf(" |\n");
}
