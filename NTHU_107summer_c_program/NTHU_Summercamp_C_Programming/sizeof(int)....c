#include<stdio.h>

int main(void){
    printf("int:%u bytes, char:%u bytes, float:%u bytes, long:%u bytes, double:%u bytes\n", sizeof(int), sizeof(char),sizeof(float), sizeof(double), sizeof(long));
    float f;
    printf("%u",sizeof(f));

}

