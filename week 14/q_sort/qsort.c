#include <stdio.h>
#include <stdlib.h> //rand()
#include <string.h>
#define SIZE 10
int compare_int (const void *a, const void *b)
{
    const int *va = (const int *) a;
    const int *vb = (const int *) b;
    return *va-*vb;//>0 a>b, <0 a<b, =0 a=b
}
int compare_double (const void *a, const void *b)
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    return (*da > *db) - (*da < *db);
    //because it's hard to judge whether double is equivalent
}

int main(void)
{
    int data1[SIZE];
    double data2[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        data1[i] = rand()%SIZE;//if dice-->rand()%6--->0~5
        data2[i] = (double) rand()/RAND_MAX;//0~1 random numbers 
        /*ex.100*(0~1)*/
        /*srand(time) to make a start point. by the time diff, the rand num will 
        different.*/
        /*but  rand() will gernerate the same order of num each time*/
    }

    printf("original: ");
    for (i=0; i<SIZE; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data1, SIZE, sizeof(int), compare_int);
    /*1.address(type:void*) 2.size 3.每一筆資料占多少空間 
    4.compare function(type:function name convert to memory address)
    int (*f)(const void *a, const void *b) variable type of function */
    for (i=0; i<SIZE; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("original: ");
    for (i=0; i<SIZE; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data2, SIZE, sizeof(double), compare_double);
    for (i=0; i<SIZE; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    return 0;
}