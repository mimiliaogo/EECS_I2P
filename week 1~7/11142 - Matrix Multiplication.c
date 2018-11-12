#include <stdio.h>
long long int a[200][200];
long long int b[200][200];

int main()
{
    int n, m, p;
    int i, j,k;
    long long int sum = 0;
//    freopen("test.txt", "r", stdin);

    while (scanf("%d%d%d", &n, &m, &p)!=EOF){
        for (i=0; i<n; i++) {
            for (j=0; j<m; j++) {
                scanf("%lld", &a[i][j]);
            }
        }

        for (i=0; i<m; i++) {
            for (j=0; j<p; j++) {
                scanf("%lld", &b[i][j]);
            }
        }


        for (i=0; i<n; i++) {
            for (j=0; j<p; j++) {
                for (k=0; k<m; k++) {
                    sum += a[i][k] * b[k][j];
                }
                if (j==p-1) printf("%lld\n", sum);
                else printf("%lld ", sum);
                sum = 0;
            }
        }

        printf("\n");
    }
        return 0;



}
