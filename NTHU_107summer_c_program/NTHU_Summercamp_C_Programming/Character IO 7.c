#include<stdio.h>
#include<string.h>
int main(void){

    char str[100];
    int i, j;

    scanf("%s", str);

    i = 0;
    j = strlen(str)-1;

    while(i<j){
        if(str[i] != str[j])
            break;
        i++;
        j--;
    }

    if(i<j)
        printf("Not a palindrome.\n ");
    else
        printf("A palindrome.\n");

}
