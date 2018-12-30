#include <stdio.h>
float entry[10][10];
float popu[10];
float temp[10];
int main()
{
    int t, n, p;
    int count;
    int never,same;
    //freopen("11758.txt", "r", stdin);
    scanf("%d", &t);
    int i, j;
    while (t>0) {
        t--;
        never = 0;
        scanf("%d", &n);
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                scanf("%f", &entry[i][j]);
            }
        }
        for (i=0; i<n; i++) {
            scanf("%f", &popu[i]);
        }
        scanf("%d", &p);
        count = 0;
        same = 0;
        while (popu[0]>p&&never==0) {
            count++;
            for (i=0; i<n; i++) {
                for (j=0; j<n; j++) {
                    temp[i]+=popu[j]*entry[i][j];
                }
            }
    //test

            for (i=0; i<n; i++) {
                if (temp[i]==popu[i]) same++;
                popu[i] = temp[i];
                temp[i] = 0;
            }
    //testing
//            for (i=0; i<n; i++) {
//                printf("%.1f\n", popu[i]);
//            }

            if (same==n&&popu[0]>p) never = 1;

        }
        if (never==1) printf("Never\n");
        else printf("%d\n", count);
    }

}
