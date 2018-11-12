#include <stdio.h>
char str[200001];
char chnum[10000001];
char benum[10000001];
int main()
{

    long long int n, m, i, j;
    scanf("%lld%lld", &n, &m);
    scanf("%s", str);
    scanf("%s", chnum);
    scanf("%s", benum);
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (str[i]==chnum[j]) {
                str[i] = benum[j];

            }
//            printf("str[%d]:%c\n", i, str[i]);
        }
    }
    printf("%s", str);

}
