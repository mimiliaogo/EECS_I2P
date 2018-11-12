#include <stdio.h>

int main()
{
    char str[1002];
    int i = 0;
    int k =0;
    int size;
    char first;
    scanf("%s", str);
    while (str[i]!='\0') {
        i++;
    }
    size = i ;// exclude 0
    while (k<size) {
        i=0;
        first = str[0];
        while (i<size-1) {
            str[i] = str[i+1];
            i++;
        }
        str[size-1] = first;
        printf("%s\n", str);
        k++;
    }
    return 0 ;
}
