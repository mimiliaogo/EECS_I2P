#include <stdio.h>
#define N 9


void getCoFactor(int mat[N][N], int temp[N][N], int row, int col, int n) {
    int i, j, k=0, t=0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i!=row&&j!=col) {
                temp[k][t++] = mat[i][j];
                if (t==n-1) {
                    t = 0;
                    k++;
                }
            }
        }
    }
}
long long int determinant(int mat[N][N], int n) {
    long long int d = 0L;
    int i;
    int temp[N][N];
    int sign = 1;
    if (n==1) return mat[0][0];
    for (i=0; i<n; i++) {
        getCoFactor(mat, temp, 0, i, n);
        d += sign * mat[0][i] * determinant(temp, n-1);
        sign = -sign;
    }
    return d;
}
int main()
{
    int mat[N][N];
    int n, i, j;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("%ld\n",determinant(mat, n));
    return 0;

}
