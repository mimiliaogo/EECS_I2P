#include<stdio.h>

int main(void)
{
    int x, y, z;
    int * ptr;

    scanf("%d", &y);

    printf("ptr: %p\n", ptr);
    ptr = &y;
    /*y����m�s��ptr�o�ӫ����ܼ�(��ptr���Vy)
            ��ptr�s�_��*/

    z = y + 1;
    ptr = &z;

    x = *ptr;//x = z; *ptr ���X�̭�����
    printf("x:%d, y:%d, z:%d, *ptr:%d, ptr:%p, &z:%p,\n",x,y,z,*ptr,ptr,&z);

    *ptr = 0;//z��m�᭱���ȳQ0���N
    printf("x:%d, y:%d, z:%d, *ptr:%d, ptr:%p, &z:%p,\n",x,y,z,*ptr,ptr,&z);
}
