#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void){

     int n;
     int i;
     Letter *letters;

     // Read inputs
     scanf("%d", &n);
     letters = (Letter*)malloc(sizeof(Letter)*n);
     for(i=0; i<n; i++)
          scanf("%d %s", &(letters[i].zipcode), letters[i].name);

     // Sort the data
     qsort((void*)letters, n, sizeof(Letter), compare);

     // Output result
     for(i=0; i<n; i++)
          printf("%d %s\n", letters[i].zipcode, letters[i].name);

     free(letters);

     return 0;
}