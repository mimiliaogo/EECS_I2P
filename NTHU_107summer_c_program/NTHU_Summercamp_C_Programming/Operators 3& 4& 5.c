#include<stdio.h>
int main(void){
    int x,y;
    x += 5;
    x = x + 5;

    y %= 7;
    y = y % 7;

    //型別轉換(expression)
    char ch;
    int i;
    float fl;

    ch = 'C';
    i = ch;
    fl = i;
    printf("ch=%c, i=%d, fl=%2.2f\n", ch, i, fl);
    ch = ch + 1;
    i = fl + 2*ch; //ch turn into int 
    fl = 2.0*ch + i;
    printf("ch=%c, i=%d, fl=%2.2f\n", ch, i, fl);


    //型別轉換
     unsigned int a;
     int b;

     a = 10;
     b = -3;
     printf("%u, %u\n", a, b);
     printf("%d\n", a < b); //成立1 opposite 0 (int turn into unsigned int)

     //examples

     int xx;
     xx= 2.3 +2.8;

     printf("%d\n", xx);

     xx = (int)2.3 + (int)2.8; //無條件捨去

     printf("%d\n", xx);


}
