#include <stdio.h>

int main()
{
    int * ap;
    int x;
    int a[5];
    char c;
    void * vp; // generally used
    /* legally obtain a address */
    ap = &x;
    ap = a;
    ap = ap + 10000;
    *(ap-10000) = 3;
    /* make sure the address is legal */
    vp = &x;
    * ((int *)vp) = 10000; //(int *)vp recast the type of the vp to int pointer

    vp = &c;
    * ((char *)vp) = 'a';

    printf("%d\n%c\n", x, c);

}

