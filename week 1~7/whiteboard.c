#include <stdio.h>
#define NQ 6

/* q[i] 記錄的是在第 i 列 (row) 出現的皇后，要擺在第幾行 (column) */
/* 譬如，q[] 的內容如果是 {2, 0, 3, 1}，表示四個皇后分別放在棋盤的 (0,2), (1,0), (2,3), (3,1) 四個位置 */

int q[NQ] = {0};
int board[NQ][NQ];
void place(int row);
int valid(int row, int col);
void display(void);

int main(void)
{

	place(0);
	return 0;
}

/*
判斷目前的狀況下，如果在 row, col 位置放入新的皇后
是否會和之前的皇后衝突
如果是合法的放置方式 return 1;
如果有衝突 return 0;
*/
int valid(int row, int col)
{
	int i;
	for (i=0; i<=row-1; i++) {

		if ( q[i]==col||q[i]==col+row-i||q[i]==col-row+i) return 0;

	}
	return 1;
}

void display(void)
{
	int i, j;
	for (i=0; i<NQ; i++) {
        for (j=0; j<NQ; j++) {
            if (j==q[i]) putchar('@');
            else putchar('0');
        }
        printf("\n");
	}
	printf("\n");
}

void place(int row)
{
	int j;
	if (row == NQ) {
		display();
	} else {
		for (j=0; j<NQ; j++) {
			if (valid(row, j)) {
				q[row] = j;
				place(row+1);

			}
		}
	}
}
