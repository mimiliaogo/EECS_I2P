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

