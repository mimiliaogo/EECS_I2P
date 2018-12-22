#include <stdlib.h>
#include "function.h"

#define RED 0
#define BLUE 1
#define ODD 1
#define EVEN 0

int compare(const void *a, const void *b) 
{
    Floor *pa = (Floor *)a;
    Floor *pb = (Floor *)b;
    return (pa->size-pb->size);


}

// Modify the design function
int design(int floorNum, Floor floorArr[]) {
    int height, color;
    int idx;
    int sum;

    qsort(floorArr, floorNum, sizeof(Floor), compare);

    height = 0;
    color = (floorArr[0].color == 'B') ? BLUE : RED;
    sum = (floorArr[0].size%2==1) ? ODD : EVEN;
    for (idx = 0; idx < floorNum; idx++) {
        if (color == BLUE && floorArr[idx].color == 'B'&&sum == ODD && floorArr[idx].size%2==1) {
            height++;
            color = RED;
            sum = EVEN;
        }
        else if (color == BLUE && floorArr[idx].color == 'B'&&sum == EVEN && floorArr[idx].size%2==0) {
            height++;
            color = RED;
            sum = ODD;
        }
        else if (color == RED && floorArr[idx].color == 'R'&&sum == EVEN && floorArr[idx].size%2==0) {
            height++;
            color = BLUE;
            sum = ODD;
        }
        else if (color == RED && floorArr[idx].color == 'R'&&sum == ODD && floorArr[idx].size%2==1) {
            height++;
            color = BLUE;
            sum = EVEN;
        }
    }
    return height;
}