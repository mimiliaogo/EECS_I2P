#include<stdio.h>
void swap(int * ,int *);
int main(void)
{
    int x, y;
    scanf("%d%d",&x, &y);
    printf("&x: %p, x:%d, &y: %p, y:%d\n", &x, x,&y, y);
    swap(&x, &y);
    printf("&x: %p, x:%d, &y: %p, y:%d\n", &x, x,&y, y);

    return 0;
}

void swap(int * a, int * b)
{
    int tmp;
    printf("a: %p,*a:%d, b: %p *b:%p\n", *a, *b);
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("a: %p,*a:%d, b: %p *b:%p\n", *a, *b);

}
