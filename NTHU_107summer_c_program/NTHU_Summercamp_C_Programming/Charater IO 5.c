#include <stdio.h>
#include <ctype.h>
/* 字元轉數值 */
int main()
{
    char ch;
    int x = 0;

    while ((ch = getchar()) != '\n') {
        if (!isdigit(ch)) break;

        x = 10 * x + (ch - '0');



    }
    printf("%d", x);



}
