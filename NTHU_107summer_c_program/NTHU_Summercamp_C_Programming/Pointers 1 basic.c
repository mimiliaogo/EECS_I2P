#include<stdio.h>

int main(void)
{
    int x, y, z;
    int * ptr;

    scanf("%d", &y);

    printf("ptr: %p\n", ptr);
    ptr = &y;
    /*y的位置存到ptr這個指標變數(把ptr指向y)
            用ptr存起來*/

    z = y + 1;
    ptr = &z;

    x = *ptr;//x = z; *ptr 取出裡面的值
    printf("x:%d, y:%d, z:%d, *ptr:%d, ptr:%p, &z:%p,\n",x,y,z,*ptr,ptr,&z);

    *ptr = 0;//z位置後面的值被0取代
    printf("x:%d, y:%d, z:%d, *ptr:%d, ptr:%p, &z:%p,\n",x,y,z,*ptr,ptr,&z);
}
