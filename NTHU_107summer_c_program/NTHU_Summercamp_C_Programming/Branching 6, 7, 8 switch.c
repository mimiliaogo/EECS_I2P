#include<stdio.h>
#include<ctype.h>
int main(void){

    int ch;
    printf("Enter a letter or type # to quit: ");
    while((ch = getchar()) != '#'){
        if(ch == '\n')
            continue;
        if(isalpha(ch)){
            switch (ch){
            case 'a':
            case 'A':
                printf("Apple.\n");
                break;
            case 'b':
            case 'B':
                printf("Book\n");
                break;

            default:
                printf("???\n");
            }

        }

        while(getchar()!= '\n')
            continue;//jump to the  the beginning of most closest the loop
        printf("Enter another letter: ");
            }
    }


