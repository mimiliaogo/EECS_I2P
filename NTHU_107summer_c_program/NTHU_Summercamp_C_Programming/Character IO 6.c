#include<stdio.h>

int main(void){

    char str[100];
    int i,x;

    scanf("%s", str);
    // '\0' -> end


    i = 0;
    x = 0;
    while(str[i]!='\0'){
        if(!isdigit(str[i]))break;
        x = x*10 + str[i]-'0';
        i++;
    }
    printf("x = %d\n", x);



 /*   printf("[0]: %c, %d\n", str[0], str[0]);
    printf("[1]: %c, %d\n", str[1], str[1]);
    printf("[2]: %c, %d\n", str[2], str[2]);
    printf("[3]: %c, %d\n", str[3], str[3]);

    str[2] = '\0';//提前結束
    str[3] = 15;//把0改掉了，程式不知道何時結束

    printf("%s\n", str);
    */
    return 0;
}




