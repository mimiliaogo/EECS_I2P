/*combine struct*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
    double speed;
}Car;
int cmp(const void * a, const void * b)
{
    Car *pa = (Car *) a;
    Car *pb = (Car *) b;
    if (pa->speed > pb->speed) return 1;
    else if (pa->speed < pb->speed) return -1;
    else return 0;
}


void show(Car *cp)
{
    printf("(%d, %d): %.2lf\n", cp->x, cp->y, cp->speed);
}
int main()
{
    Car a[10];
    int i;

    for (i=0; i<10; i++) {
        a[i].x = rand()%10;
        a[i].y = rand()%10;
        a[i].speed = 300*(double) rand()/RAND_MAX;
    }
    for (i=0; i<10; i++) show(&a[i]);
    qsort(a, 10, sizeof(Car), cmp);
    for (i=0; i<10; i++) show(&a[i]);
    return 0;
}
