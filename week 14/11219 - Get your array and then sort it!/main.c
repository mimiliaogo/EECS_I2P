#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

int* readInput() {
    int i, N, *seq;
    scanf("%d", &N);
    seq = (int*)malloc(sizeof(int)*(N + 1));
    seq[0] = N;
    for(i=1; i<N+1; i++)
        scanf("%d", &seq[i]);
    return seq;
}

void my_sort(int* B)
{
    int *seq = *B;
   
    int i, j, temp;
    for (i=1; i<=seq[0]; i++) {
        for (j=i; j<=seq[0]; j++) {
            if (seq[i]>seq[j]) {
                temp = seq[i];
                seq[i] = seq[j];
                seq[j] = temp;
            }
            
        }
    }

}
int main() {
    int i;
    int *A = readInput();
    my_sort((int*)&A);
    printf("%d", A[1]);
    for(i=2;i<A[0]+1;i++)
        printf(" %d", A[i]);
    printf("\n");
    return 0;
}


