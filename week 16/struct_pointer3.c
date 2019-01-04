#include <stdio.h>
#include <stdlib.h>
typedef struct t_data {
    int size;
    int * ptr;
} DATA;
void create_data(DATA *z, int sz)
{
    int * t;
    int i;
    z->size = sz;
    z->ptr = (int *) malloc(sz*sizeof(int));
    t = z->ptr;
    for (i=0; i< sz; i++)  {
        t[i] = i;
    }
}
void show_data(DATA  d) //d=x copy the two 欄位
{
    int i;
    printf("%u\n", sizeof(d));
    for (i=0; i<d.size; i++) {
        printf("%d ", (d.ptr)[i]);
        if ((i+1)%10 == 0) printf("\n");
    }
}

void delete_data(DATA *z) //z = &x
{
    free(z->ptr);
    z->ptr = NULL;
    z->size = 0;
}
DATA clone_data(DATA x)
{
    int i;
    DATA y;
    y.size = x.size;
    y.ptr = (int *) malloc(y.size*sizeof(int));//放在不同地址
    for (i=0; i<y.size; i++) {
        (y.ptr)[i] = (x.ptr)[i];
    }
    return y;//把y的內容複製到x_clone，y只是個local variable
}

int main(void)
{
    DATA x = {0, NULL} , x_clone = {0, NULL};
    create_data(&x, 100);
    show_data(x);
    x_clone = clone_data(x);  //why not x_clone = x?It will get the same ptr。
    //不會因為原來的被刪除而消失 
    delete_data(&x);
    show_data(x_clone);

    return 0;
}