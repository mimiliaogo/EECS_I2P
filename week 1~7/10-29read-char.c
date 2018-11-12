#include <stdio.h>
int main()
{
    char ch;
    while (scanf("%c", &ch) != EOF) {
        printf("%c\n", ch);
        while (getchar()!='\n');//把他讀掉
    }

    char cha;
    while ((cha=getchar()) != EOF) {
        printf("%c\n", cha);
        while (getchar()!='\n');//把他讀掉
    }


    int x;
    while (scanf("%d", &x) != EOF) {
        printf("%d\n", x);
        while (getchar()!='\n');//解決若讀到不是%d的東西，把他讀掉
    }

    int y;
    while (scanf("%d", &y) == 1) {
        printf("%d\n", x);
    }//另一解決方法


}
