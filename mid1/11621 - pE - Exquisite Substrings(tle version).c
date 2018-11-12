#include<stdio.h>
#include<string.h>
//#define OJ
int check(int len);
char s[2000];
int main()
{
    int len;
#ifndef OJ
    freopen("11619.txt", "r", stdin);
#endif // OJ
    while (scanf("%s", s)!=EOF) {
        len = strlen(s);
        printf("%d\n", check(len));
    }
}
int check(int len)
{
    int i,j;
    int k=0;
    int ans=0;
    int isex=1;
    for (i=0; i<len; i++) {
        for (j=len-1; j>i; j--) {
            if (s[i]!=s[j]){
                continue;
            }
            else {
                k=0;
                while ((i+k)<=(j-k)) {
                    if (s[i+k]!=s[j-k]) {
                        isex=0;
                        break;
                    }
                    k++;
                }
                if (isex==1) ans++;
            }
            isex=1;
        }

    }

    return ans;
}

