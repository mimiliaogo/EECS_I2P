#include <stdio.h>
#include <stdint.h>


void Print(int m, int n, int matrix[][500] ) {
    for ( int i = 0; i < m; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf("%d%c", matrix[i][j], " \n"[j==n-1] );
        }
    }
}
void Transpose(int *row, int *col, int matrix[][500])
{
    int i, j;
    int tempar[500][500];
    int temp;
    for (i=0; i<*row; i++) {
        for (j=0; j<*col; j++) {
            tempar[j][i] = matrix[i][j];
        }
    }

    temp = *row;
    *row = *col;
    *col = temp;

    for (i=0; i<*row; i++) {
        for (j=0; j<*col; j++) {
            matrix[i][j] = tempar[i][j];
        }
    }


}


int32_t main(){
    int matrix[500][500];
    int row, col;
    scanf("%d %d", &row, &col);
    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            scanf("%d", &matrix[i][j]);
        }
    }
    Transpose( &row, &col, matrix);
    Print( row, col, matrix );
    return 0;
}
