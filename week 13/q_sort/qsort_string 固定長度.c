/*直接把兩個字串交換，或字串很長，很麻煩*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int main(void)
{
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "aab", "abc", "aaa", "abb", "acb"
    };
    int i;

    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }
    printf("\n");
    qsort(strs, SIZE, 4*sizeof(char), (int (*) (const void *, const void *))strcmp);
    /*強制轉型strcmp成(int (*) (const void *, const void *))type*/
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }

    return 0;
}
