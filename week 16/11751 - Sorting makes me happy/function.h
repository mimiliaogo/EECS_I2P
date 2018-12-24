#ifndef _FUNCTION_H
#define _FUNCTION_H

typedef struct {
	int value;
	char str[30];
	float x;
} MyData;

int compare_function(const void** a, const void** b)
{
    MyData* pa = *(MyData**)a;
    MyData* pb = *(MyData**)b;
    if (pa->value>pb->value) return 1;
    else if (pa->value<pb->value) return -1;
    else {
        if (strcmp(pa->str, pb->str)>0) return 1;
        else if (strcmp(pa->str, pb->str)<0) return -1;
        else {
            return (pa->x>pb->x) - (pa->x<pb->x);
        }
    }
}

#endif
