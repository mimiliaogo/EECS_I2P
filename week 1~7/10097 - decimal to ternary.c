#include <stdio.h>

int main()
{
    int ter[10];
    int dec;
    int num, size;
    int i = 0;
    scanf("%d", &dec);
    scanf("%d", &num);
    while (dec>0) {
        ter[i] = dec % 3;
        dec/=3;
        i++;
    }
    size = i;
    while (num>size) {
        printf("%d", 0);
        num--;
    }
    for (i=size-1; i>=0; i--) {
            printf("%d", ter[i]);
    }
    printf("\n");



}
