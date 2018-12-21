#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct
{
   int ID;
   int Chinese, English, math, science;
   int total;
} Grade;
int cmp_ascend(const void* a, const void *b)
{
    Grade*pa = (Grade*)a;
    Grade*pb = (Grade*)b;
    if (pa->total>pb->total) return 1;
    else if(pa->total<pb->total) return -1;
    else {
        if (pa->Chinese>pb->Chinese) return 1;
        else if(pa->Chinese<pb->Chinese) return -1;
        else {
            if (pa->English>pb->English) return 1;
            else if(pa->English<pb->English) return -1;
            else {
                if (pa->math>pb->math) return 1;
                else if(pa->math<pb->math) return -1;
                else {
                    if (pa->science>pb->science) return 1;
                    else if(pa->science<pb->science) return -1;
                    else {
                        if (pa->ID>pb->ID) return 1;
                        else if(pa->ID<pb->ID) return -1;
                        else return 0;
                    }
                }
            }
        }
    }
}
int cmp_descend(const void* a, const void *b)
{
    Grade*pa = (Grade*)a;
    Grade*pb = (Grade*)b;
    if (pa->total>pb->total) return -1;
    else if(pa->total<pb->total) return 1;
    else {
        if (pa->Chinese>pb->Chinese) return -1;
        else if(pa->Chinese<pb->Chinese) return 1;
        else {
            if (pa->English>pb->English) return -1;
            else if(pa->English<pb->English) return 1;
            else {
                if (pa->math>pb->math) return -1;
                else if(pa->math<pb->math) return 1;
                else {
                    if (pa->science>pb->science) return -1;
                    else if(pa->science<pb->science) return 1;
                    else {
                        if (pa->ID>pb->ID) return 1;
                        else if(pa->ID<pb->ID) return -1;
                        else return 0;
                    }
                }
            }


        }
    }

}
void sortGrade(Grade *gList, int n, char *order)
{
    int i;
    for (i=0; i<n; i++) {
        (gList+i)->total = (gList+i)->Chinese+(gList+i)->English+(gList+i)->math+(gList+i)->science;
    }

    if (order[0]=='a') {
        qsort(gList, n, sizeof(Grade), cmp_ascend);
    }
    else {
        qsort(gList, n, sizeof(Grade), cmp_descend);
    }

}
#endif
//  sortGrade(gradeList, n, order);
