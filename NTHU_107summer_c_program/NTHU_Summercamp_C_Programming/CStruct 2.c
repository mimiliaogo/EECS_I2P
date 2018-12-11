#include<stdio.h>

struct t_node{
    int data;
    struct t_node *nextPtr;//指向自己的指標
};

int main()
{

    struct t_node n1, n2;

    n1.nextPtr = &n2;
    n2.nextPtr = &n1;

    n1.nextPtr->data = 20;
    n2.nextPtr->data = 10;

    printf("n1.data: %d, n2.data: %d\n", n1.data, n2.data);

    return 0;


}
