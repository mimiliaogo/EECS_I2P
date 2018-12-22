//
// Created by 贾松昊 on 2017/12/21.
//

#ifndef TEST_FOR_C_FUNCTION_H
#define TEST_FOR_C_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa-*pb);
}

void assign(char* x, char* y, size_t size)
{
    int tmp;
    int *px = (int*)x;
    int *py = (int*)y;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void mysort(void* arr, size_t count, size_t size, int (*cmp) (const void*, const void*))
{
    char* a = (char*)arr;
    int i, j;
    i=1;
    while (i<count) {
        j=i;
        while(j>0&&compare((a+j*size),(a+(j-1)*size))<0) {
            assign(a+j*size,a+(j-1)*size, size);
            j--;
        }
        i++;
    }
}

#endif //TEST_FOR_C_FUNCTION_H
