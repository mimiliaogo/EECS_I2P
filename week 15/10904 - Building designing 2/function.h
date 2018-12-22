#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct {
    char color;
    unsigned int size;
} Floor;

int compare(const void *a, const void *b);

int design(int floorNum, Floor floorArr[]);

#endif 