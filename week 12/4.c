#include <stdio.h>
#define sometype double
/*
*a
a[]
*/
void show_2d_int_array(int (*pz) [2], int );
int main()
{
    int z[4][2] = {{1,2}, {3,4}, {5,6}, {7,8}};
    int (*pz) [2];//打開門看到的是int [2]的東西
    pz = z;
    /*
    int *   ppz[2]; //the array of int address
    ppz[0] = &xx;
    ppz[1] = &xx;
    */

    int x[4] = {1, 2, 3, 4};
    int * px;
    px = x;

    sometype y[4];
    sometype *py;
    py = y;


    printf("%d\n", pz[2][1]);
    /*
    *(pz[2]+1)
    *(*(pz+2)+1)
    */
    return 0;
}

void show_2d_int_array(int pz[][2], int n)
{
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<2; j++) {
            printf("%d ", pz[i][j]);
        }
        printf("\n");
    }
}
