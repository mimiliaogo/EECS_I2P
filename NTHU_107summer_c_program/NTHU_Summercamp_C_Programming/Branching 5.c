#include<stdio.h>

int main(void){
    int x = 5;
    int y = 3;

    if(x > 2 && y == 3)
        printf("1) True\n");
    else
        printf("1) False\n");
    if( !(x < 2 || y == 3))
        printf("2) True\n");
    else
        printf("2) False\n");
    if(x != 0 && y)
        printf("3) True\n");
    else
        printf("3) False\n");
    if(x == 0 || !y)//y isn't y
        printf("4) True\n");
    else
        printf("4) False\n");
    if( !(y>5 || y<2)&& !(x%5) )//left true,right: not 0 is true,0 is false
        printf("6) True\n");
    else
        printf("6) False\n");
    if(!x && x)
        printf("7) True\n");
    else
        printf("7) False\n");

}
