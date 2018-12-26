#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int x;
    int y;
    char str[25];
    int px;
} Car;
int cmp(const void *a, const void *b)
{
    Car* pa = (Car*)a;
    Car* pb = (Car*)b;
    return (pa->px<pb->px) - (pa->px>pb->px);
}
int cmp_str(const void *a, const void *b)
{
    Car*pa = (Car*)a;
    Car*pb = (Car*)b;
    return strcmp(pa->str, pb->str);
}
int main()
{
    int n, x, y;
    int i;
    scanf("%d%d%d", &n, &x, &y);

    Car *data = (Car*) malloc(sizeof(Car)*n);
    for (i=0; i<n; i++) {
        scanf("%s", data[i].str);
        scanf("%d%d", &data[i].x, &data[i].y);
        data[i].px = data[i].x-data[i].y;
    }
    qsort(data, n, sizeof(Car), cmp);

    qsort(data, x, sizeof(Car), cmp_str);

    for (i=0; i<x; i++) {
        printf("%s\n", data[i].str);
    }
}
