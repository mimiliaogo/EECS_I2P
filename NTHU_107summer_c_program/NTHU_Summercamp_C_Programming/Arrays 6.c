#include<stdio.h>
#define SIZE 4

int main(void)
{
 /*   int a[10];

    printf("%p %p\n", a, &a[0]);
    //�}�C���Ĥ@�Ӥ������O�����m ��z�L�W�٨��o����m�@��
 */


    char cdata[SIZE] = {'A', 'M', 'C', 'D'};
    char * ptc;
    int idata[SIZE] = {1,2,3,4};
    int * pti;
    int k;
    ptc = cdata;
    pti = idata;

    for(k=0; k<SIZE; k++){
        printf("ptc+%d: %p %c    pti+%d:   %p %d\n", k,
               ptc+k, *(ptc+k), k,pti+k, *(pti+k)  );
    }
    //��m�첾�@�� �`�N���O���骺�ܤ�
    return 0;
}
/*
ptc+k
=&cdata[k]
*/
