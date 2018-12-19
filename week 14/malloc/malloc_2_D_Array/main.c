#include <stdio.h>
int main()
{
    int i, j;
    int *a;
    int **b;
    /*simulate this
    int z[100][50];
    */
    b = (int* *)malloc(sizeof(int*)*100);
    a = (int*)malloc(sizeof(int)*50*100);
    //important
    for (i=0; i<100; i++) {
        b[i] = &a[i*50];
    }
    /* wrong way cuz address isn't continuous
    for (i=0; i<100; i++) {
        a = (int*)malloc(sizeof(int)*50);//每次取到的地址不一樣
        b[i] = a; //b[i]save the address of a(a 50 long string)
    }
    */
    for (i=0; i<100; i++) {
        for (j=0; j<50; j++) {
            b[i][j] = i*j;
            //a[i] = i*j;
        }
    }

    /*wrong 
    //free  有多少malloc就要free多少
    for (i=0; i<100; i++) {
        free(b[i]);//100 address to destroy
       
    }
    free(b);
    */

   free(a);
   free(b);
}