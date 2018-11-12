#include <stdio.h>
int board[5][5];
void show_board(void)
{
    int i, j;
    for (i=1; i<=4; i++) {
        for (j=1; j<=4; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
int valid(int row, int col);
void place(int row);
int main()
{
    place(1);
    return 0;
}
int valid(int row, int col)
{
    int i, j;

    for (i=1; i<row; i++) {
        if (board[i][col]) return 0;
    }
    i = 1;
    for (j=col+row-i; j>col,j<=5; j--) {
        if (board[i][j]==1) return 0;
        i++;
    }
    i = 1;
    for (j=col-row+i; j<col,j>=0; j++) {
        if (board[i][j]==1) return 0;
        i++;
    }

    return 1;
}
void place(int row)
{
    int j;
    if (row>4) show_board();
    else {
        for (j=1; j<=4; j++) {
            if (valid(row, j)) {
                board[row][j] = 1;
                place(row+1);
                board[row][j] = 0;
            }
        }
    }
}
