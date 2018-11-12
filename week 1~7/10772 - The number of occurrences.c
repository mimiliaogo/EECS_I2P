#include <stdio.h>
#include <string.h>
int findsub(int smlen, int bilen);
char small[10];
char big[100];
int main()
{
    int smlen, bilen;
    int n;
    int max = 0;
    scanf("%s", small);
    smlen = strlen(small);
    scanf("%d", &n);
    while (n>0) {
        scanf("%s", big);
        bilen = strlen(big);
        if (findsub(smlen, bilen)>max)
            max = findsub(smlen, bilen);
        n--;
    }
    printf("%d", max);

}
int findsub(int smlen, int bilen)
{
    int i,k,j;
    int isfind = 1;
    int ans = 0;
    for (i=0; i<bilen; i++) {
        for (j=0; j<smlen; j++) {
            if (small[j]!=big[i+j]) {
                isfind = 0;
                break;
            }
        }
        if (isfind==1) ans++;
        isfind = 1;
    }
    return ans;


}
