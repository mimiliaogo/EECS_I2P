/* 延伸Strings 1,2 */
/* hard to understand */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum {MAX_LEN=256};

/* char* realloc(char *oldptr, unsigned size); */

int main(void)
{
    char **p;
    char **q;
    char buf[MAX_LEN+1];
    int maxline = 1;
    int i, j;

    p = (char **) malloc (maxline*sizeof(p[0]) );
    i=0;
    while(fgets(buf, MAX_LEN + 1, stdin) != NULL) {
        if (i >= maxline) {
            maxline *= 2;
            q = (char **) realloc(p, maxline*sizeof(p[0]));
            if (q == NULL) {
                for(j=0; j<i; j++)
                    free(p[j]);
                free(p);
                return EXIT_FAILURE;
            }
            p = q;
        }
        p[i] = (char * )malloc(strlen(buf)+1);//最後為字串的結尾符號
        if (p[i] == NULL) {
                for(j=0; j<i; j++)
                    free(p[j]);
                free(p);
                return EXIT_FAILURE;

         }
        strcpy(p[i], buf);//把後面指標所記住的暫存字串存到前面指標記住的位置
        i++;

    }

    for (j=0; j<i; j++) {
        printf("%s", p[j]);
        free(p[j]) ;
    }
    for (j=0; j<i; j++) {
        free(p[j]);
    }
    free(p);

    return 0;

}

