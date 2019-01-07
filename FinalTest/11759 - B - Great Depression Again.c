#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int x;
    int y;
    char str[25];
    int px;
} Car;
int cmp_px_big(const void *a, const void *b)
{
    Car* pa = (Car*)a;
    Car* pb = (Car*)b;
    return pb->px-pa->px;
}
int cmp_px_small(const void *a, const void *b)
{
    Car* pa = (Car*)a;
    Car* pb = (Car*)b;
    return pa->px-pb->px;
}

int cmp_abx(const void *a, const void *b)
{
    Car* pa = (Car*)a;
    Car* pb = (Car*)b;
    return pb->x-pa->x;

}

int cmp_aby(const void *a, const void *b)
{
    Car* pa = (Car*)a;
    Car* pb = (Car*)b;
    return pb->y-pa->y;

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
    int stick, tmp=0;
    int i, j;
    int max = 0;
    scanf("%d%d%d", &n, &x, &y);

    Car *data = (Car*) malloc(sizeof(Car)*n);
    for (i=0; i<n; i++) {
        scanf("%s", data[i].str);
        scanf("%d%d", &data[i].x, &data[i].y);
        data[i].px = data[i].x-data[i].y;
    }
    //compare x-y
    for (i=0; i<=n-x-y; i++) {
        qsort(data, n, sizeof(Car), cmp_px_big);
        qsort(data, x+i, sizeof(Car), cmp_abx);
        for (j=0; j<x; j++) {
            tmp += data[j].x;
        }
        qsort(data, n, sizeof(Car), cmp_px_small);
        qsort(data, n-x-i, sizeof(Car), cmp_aby);
        for (j=0; j<y; j++) {
            tmp += data[j].y;
        }
        if (tmp>max) {
            max = tmp;
            stick = i;
        }
        tmp = 0;
    }
    qsort(data, n, sizeof(Car), cmp_px_big);
    qsort(data, x+stick, sizeof(Car), cmp_abx);
    qsort(data, x, sizeof(Car), cmp_str);

    for (i=0; i<x; i++) {
        printf("%s\n", data[i].str);
    }
}
