#include <stdio.h>
int main()
{
    char ch;
    while (scanf("%c", &ch) != EOF) {
        printf("%c\n", ch);
        while (getchar()!='\n');//��LŪ��
    }

    char cha;
    while ((cha=getchar()) != EOF) {
        printf("%c\n", cha);
        while (getchar()!='\n');//��LŪ��
    }


    int x;
    while (scanf("%d", &x) != EOF) {
        printf("%d\n", x);
        while (getchar()!='\n');//�ѨM�YŪ�줣�O%d���F��A��LŪ��
    }

    int y;
    while (scanf("%d", &y) == 1) {
        printf("%d\n", x);
    }//�t�@�ѨM��k


}
