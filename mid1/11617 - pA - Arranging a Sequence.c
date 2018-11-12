#include <stdio.h>
int check[200001] = {0};
int re[100001] = {0};
int main()
{
    int n,m;
    int i;
    scanf("%d%d", &n, &m);
    for (i=0; i<m; i++) {
        scanf("%d", &re[i]);
    }
    check[0] = 1;
    for (i=m-1; i>=0; i--) {
        if (check[re[i]]==0) {
            printf("%d\n", re[i]);
            check[re[i]] = 1;
        }
    }
    for (i=1; i<=n; i++) {
        if (check[i]==0) {
            printf("%d\n", i);
        }
    }


}
