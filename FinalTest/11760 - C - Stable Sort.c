#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char str[25];
    int score;
    int order;
} Student;
int cmp(const void *a, const void *b){
    Student*pa = (Student*)a;
    Student*pb = (Student*)b;
    if (pa->score>pb->score) return -1;
    else if (pa->score<pb->score) return 1;
    else {
        return (pa->order-pb->order);
    }
}
int main()
{
    int n, i;
    scanf("%d", &n);
    Student * data =(Student *) malloc(sizeof(Student)*n);
    for (i=0; i<n; i++) {
        scanf("%s", data[i].str);
        scanf("%d", &data[i].score);
        data[i].order = i;
    }
    qsort (data, n, sizeof(Student), cmp);
    for (i=0; i<n; i++) {
        printf("%s\n", data[i].str);
    }
    free(data);

    return 0;
}
