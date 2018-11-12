#include <stdio.h>
char str1[1001];
char str2[1001];
int main()
{

    int len1, len2;
    int i,j;
    int issub=0;
    int max=0;
    int p;
    while ((scanf("%s", &str1))!=EOF) {
            scanf("%s", &str2);
            len1 = strlen(str1);
            len2 = strlen(str2);
            issub = 0;
            max = 0;

//            for (i=0; i<len1; i++) {
//                for (j=i+1; j<len; j++) {
//
//                    for (int k = 0; k < len2; k++){
//                        for(int p = 0; p < j - i; p++){
//                                if (str1[i+p] == str2[k+p])
//                        }
//                    }
//                }
//            }

            for (i=0; i<len1; i++) {
                for (j=0; j<len2; j++) {
                    for (p=0; p+i<len1,p+j<len2; p++) {
                        if (str1[i+p]!=str2[j+p]) break;
                        else issub = 1;
                    }
                    if (issub==1) {
                        if (p>max) max = p;
                    }
                }
            }

            printf("%d\n", max);
    }
}
