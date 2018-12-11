#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {MAX_LEN=256, MAX_LINE=1000};

int main(void)
{
    char * p[MAX_LINE];
    char buf[MAX_LEN+1];
    int i, j;

    i=0;
    while(i<MAX_LEN && (fgets(buf, MAX_LEN + 1, stdin) != NULL) ) {
        /*                    字串位置 字串長度    keyboard */
        /* 讀取一整行的字串直到換行字元 */
        p[i] = (char * )malloc(strlen(buf)+1);//最後為字串的結尾符號
        if (p[i] != NULL) {
            strcpy(p[i], buf);//把後面指標所記住的暫存字串存到前面指標記住的位置
            i++;
        }
    }

    for(j=0; j<i; j++) {
        printf("%s", p[j]);
        free(p[j]) ;
    }



}
