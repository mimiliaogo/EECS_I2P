#include<stdio.h>
#define mimi 1499.99

int main(void){
    printf("%f\n",mimi); //1499.990000
    printf("%e\n",mimi); //1.4999+003
    printf("%4.2f\n",mimi); //�ܤ���ܥX4���e��(�]�t�p���I��)�p���I�����2��
    printf("%3.1f\n",mimi);
    printf("%10.3f\n",mimi);
    printf("%-10.3f\n",mimi);
    printf("%12.3e\n",mimi);
    printf("%+4.2f\n",mimi);
    printf("%010.2f\n",mimi); //�r���ƪ�������0



}

