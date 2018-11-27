#include <stdio.h>
int main()
{
    int z[4][2] = {{1,2}, {3,4}, {5,6}, {7,8}};
    /* think like this
    (int [2])z[4]   = {{1,2}, {3,4}, {5,6}, {7,8}};
    */
    // two integers to compose each array
    printf("%p\n", z);
    printf("%p\n", z[0]);
    printf("%p\n", *(z+0));
    printf("%p\n", &z[0][0]);
    /*overlap the memory address*/

    printf("%p\n", z[1]);
    printf("%p\n", z[2]);
    printf("%p\n", z[3]);
    /*
    z[0] [1]
    *(z[0]+1)

       *(ap+i) ---> ap[i]
    */
    printf("%d\n", z[0][1]);
    printf("%d\n", *(z[0]+1));//從這個記憶體位置，偏移一個位置，取值

    // remember the 2_dimension array memory address*/
    int (*pz) [2]; //expect to see 2 numbers when opening the door
    pz = z;

    return 0;
}
void show(int a[], int n)
{
    int *ip;
    for (ip=a; ip < a+n; ip++) {
        printf("| %8p", ip);
    }
    printf(" |\n");
    for (ip=a; ip< a+n; ip++) {
        printf("| %8d", *ip);
    }
    printf(" |\n");
}

