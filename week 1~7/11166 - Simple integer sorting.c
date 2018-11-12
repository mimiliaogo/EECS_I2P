#include <stdio.h>
#define OJ
int v[10001];

int main()
{
    int t; //t case
    int n; //n numbers
    int i,j;
    int temp;
#ifndef OJ
    freopen("1166.txt", "r", stdin);
#endif // OJ
    scanf("%d", &t);
    while (t>0) {
        scanf("%d", &n);
        for (i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        for (i=0; i<n; i++) {
            for (j=i; j<n; j++) {
                if (v[j]<v[i]) {
                    temp = v[j];
                    v[j] = v[i];
                    v[i] = temp;
                }
            }
        }
        for (i=0; i<n-1; i++) {
            printf("%d ", v[i]);
        }
        printf("%d\n", v[n-1]);

        t--;

    }
    return 0;
}


