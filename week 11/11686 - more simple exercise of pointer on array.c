#include <stdio.h>
#include "function.h"
void array_exchanger(int* array_a, int* array_b, int length) {
     int i;
     int temp;
     for (i=0; i<length; i++) {
        temp = array_a[i];
        array_a[i] = array_b[i];
        array_b[i]  = temp;
     }
}
