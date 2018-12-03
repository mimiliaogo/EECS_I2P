#include <stdio.h>
#define MAXNQ 8
int q[MAXNQ];
int values[9][9];
int max;
/* this show function is for testing*/
//void show()
//{
//    int i, j;
//    for (i=0; i<8; i++) {
//        for (j=0; j<8; j++) {
//            if (j==q[i]) printf("@");
//            else printf("O");
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
void count()
{
    int i, j;
    int sum = 0;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (j==q[i]) sum += values[i][j];
        }
    }
    if (sum>max) max = sum;

}
int valid(int r, int c)
{
    int i;
    for (i=0; i<r; i++) {
        if (q[i]==c) return 0;
    }
    for (i=0; i<r; i++) {
        if (i-r==q[i]-c) return 0;
        else if (i-r==c-q[i]) return 0;
    }
    return 1;
}
void place(int n);
int main()
{
    int i, j;
    int t;
    scanf("%d", &t);
    while (t>0) {
        for (i=0; i<8; i++) {
            for (j=0; j<8; j++) {
                scanf("%d", &values[i][j]);
            }
        }
        place(0);
        printf("%d\n", max);
        max = 0;
        t--;
    }

    return 0;

}
void place(int n)
{
    int i;
    if (n==8) count();
    else  {
        for (i=0; i<8; i++) {
            if (valid(n, i)) {
                q[n] = i;
                place(n+1);
            }
        }
    }
}
