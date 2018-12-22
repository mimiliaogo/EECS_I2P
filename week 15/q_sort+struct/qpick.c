/*實作qsort*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp_int(const void * a, const void * b)
{
    int *pa = (int *) a;
    int *pb = (int *) b;
    if (*pa>*pb) return 1;
    else if (*pa<*pb) return -1;
    else return 0;
}
double cmp_double(const void * a, const void * b)
{
    double *pa = (double *) a;
    double *pb = (double *) b;
    if (*pa>*pb) return 1;
    else if (*pa<*pb) return -1;
    else return 0;
}
int qpick(void*s, size_t sz, size_t bt,int (*f) (const void *, const void *));

int main()
{
    int a[100];
    double b[100];
    int i;
    for (i=0; i<10; i++) {
        a[i] = rand()/10000;
    }
    for (i=0; i<10; i++)
        b[i] = (double)rand()/RAND_MAX;

    for (i=0; i<10; i++) printf("%d %d\n", i, a[i]);
    i = qpick(a, 10, sizeof(int), cmp_int);
    printf("pick:%d %d\n", i, a[i]);

    for (i=0; i<10; i++) printf("%d %lf\n", i, b[i]);
    i = qpick(b, 10, sizeof(double), cmp_double);
    printf("pick:%d %lf\n", i, b[i]);

    return 0;
}
int qpick(void*a, size_t num, size_t sz,
         int (*cmp) (const void *, const void *))
{
    int i;
    int maxi = 0;//最大值的編號
    char * b = (char*) a;

    for (i=0; i<num; i++) {
        if ( cmp((const void*) (b+i*sz),(const void*) (b+maxi*sz)) > 0) {
            maxi = i;
        }
    }
    return maxi;
}
