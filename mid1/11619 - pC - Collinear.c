#include<stdio.h>
#define MAXPOINT 100
int counter[MAXPOINT+1]={0};
long long int x[MAXPOINT];
long long int y[MAXPOINT];
int findline(int n);
//#define OJ
int main()
{
    int t;
    int n;
#ifndef OJ
    freopen("11619.txt", "r", stdin);
#endif // OJ

    scanf("%d", &t);
    while (t>0) {
        scanf("%d", &n);
        printf("%d\n", findline(n));
        t--;
    }
}
int findline(int n)
{
    int i,j,k;
    int pts=0;
    int ans=0;
    for (i=0; i<n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    for (i=0; i<=n; i++) {
        counter[i] = 0;
    }
    for (i=0; i<n; i++) {
        for (j=i+1; j<n; j++) {
            for (k=0; k<n; k++) {
                if (((y[j]-y[i])*(x[k]-x[i]))==((y[k]-y[i])*(x[j]-x[i]))){
                    pts++;
                    /*printf("x[%d]:%d x[%d]:%d x[%d]:%d pts:%d\n",i,x[i],j, x[j],k, x[k], pts);*/
                }
            }
            counter[pts]++;
            pts=0;
        }
    }
    for (i=3; i<=n; i++) {
        ans += counter[i]*2/(i*(i-1));
    }


    return ans;
}
