#include <stdio.h>
#define NQ 6

/* q[i] �O�����O�b�� i �C (row) �X�{���ӦZ�A�n�\�b�ĴX�� (column) */
/* Ĵ�p�Aq[] �����e�p�G�O {2, 0, 3, 1}�A��ܥ|�ӬӦZ���O��b�ѽL�� (0,2), (1,0), (2,3), (3,1) �|�Ӧ�m */

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
�P�_�ثe�����p�U�A�p�G�b row, col ��m��J�s���ӦZ
�O�_�|�M���e���ӦZ�Ĭ�
�p�G�O�X�k����m�覡 return 1;
�p�G���Ĭ� return 0;
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
