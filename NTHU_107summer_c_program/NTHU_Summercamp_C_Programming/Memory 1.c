#include<stdio.h>
#include<stdlib.h>

int main()
{
    double * ptd;
    int array_size,i;

    scanf("%d", &array_size);

    ptd = (double *)malloc( array_size * sizeof(double) );
    /* original void 強制轉成double
    malloc use byte as 單位  */

    if(ptd == NULL){
        printf("Fail.\n");
        exit(EXIT_FAILURE);//define in stdlib
    }

    for (i=0; i<array_size; i++){
        ptd[i] = (double)i;//(double)rand()/RAND_MAX;
        /*(ptd+i)*/
    }
    for (i=0; i<array_size; i++){
        if( *(ptd+i)>0.5)
            printf("%d: %f\n", i, ptd[i]);
    }

    free(ptd);//將記憶體開頭傳進去，將記憶體釋放掉


    return 0;

}
