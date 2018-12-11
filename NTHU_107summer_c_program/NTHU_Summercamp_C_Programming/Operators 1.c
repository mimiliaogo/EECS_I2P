#include<stdio.h>

int main(){
  /*  int x;
    int y;
    scanf("%d%d",&x, &y);
    printf("x/y = %d\n",x/y);
    printf("x%%y = %d\n", x%y);
    printf("%d = %d * %d + %d\n", x, y, x/y, x%y);
*/

    int x = 6;
    printf("%d\n",x++);//6 先把x的數值拿來使用，在累加
    printf("%d\n",x++);//7
    printf("%d\n\n",x);//8
    x = 6;
    printf("%d\n",++x);//7 先對x做加1，把加1的數值拿來使用
    printf("%d\n",++x);//8
    printf("%d\n",x);//8






}
