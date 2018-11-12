#include <stdio.h>

int main(void)
{
    int i;
    char a[4];
    scanf("%3s", a);
    for (i=0; i<3; i++) {
        printf("%c", a[i]+'A'-'1');
    }
    return 0;
}
