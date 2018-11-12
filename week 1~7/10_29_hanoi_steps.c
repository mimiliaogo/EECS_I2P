#include <stdio.h>
void hanoi(char from, char to, char buffer, int n);
int main()
{
    int n;
	printf("Number of disks: ");
	scanf("%d", &n);
	hanoi('1', '3', '2', n);

	return 0;

}

int hanoi(char from, char to, char buffer, int n)
{
    int step=0;
    if (n==1) {
        printf("Move the top disk from Tower %c to Tower %c\n", from, to);
    }
    else {
        hanoi(from,buffer,to,n-1);// x steps
        printf("Move the top disk from Tower %c to Tower %c\n", from, to);
        /* move the last disk from a to b */
        hanoi(buffer,to,from,n-1); //x steps
        //finally 2*x+1 steps
    }

}
