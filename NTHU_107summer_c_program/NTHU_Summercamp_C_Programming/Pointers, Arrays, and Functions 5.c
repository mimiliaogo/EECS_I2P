#include<stdio.h>
void show_int_array(int a[], int n);
void show_int_2d_array(int a[][2], int k);
int main(void)
{
    int z [4] [2] = {{1,2}, {3,4}, {5,6}, {7,8} };
    /*
    two_ints z[4]
    */
    int j;

    show_int_2d_array(z,4);

    printf("\n\n");

    for(j=0; j<4; j++){
        show_int_array( z[j] , 2);
    }


    return 0;
}

void show_int_2d_array(int (* a)[2], int k)
//int a[][2]
//2讓指標知道一次跳兩格　影片中有示意圖
{
    int i,j;

    for(j=0; j<k; j++){
        for(i=0; i<2; i++){
            printf("%d ", a[j][i]);
        }
        printf("\n");

    }
}
void show_int_array(int a[], int n)// int * a
{
    int i;

    for (i=0; i<n; i++){
        printf("%d ", a[i]);//*(a+i)
    }
    printf("\n");
}
