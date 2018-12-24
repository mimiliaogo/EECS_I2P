#include <stdio.h>
#include <stdlib.h>
typedef struct _Point{
    int x;
    int y;
    struct _Point * next;//can't use Point * next cuz Point * is behind
    //the space for address is fixed so it is ok for compiler 
    //no matter how big  the struct is. only pointers can do that
} Point;

int main()
{
    int i;
    Point pt1, pt2, pt3, pt4;
    pt1.x = 5;
    pt1.y = 10;
    pt1.next = &pt2 ;

    pt2.x = 7;
    pt2.y = 15;
    pt2.next = &pt3;

    pt3.x = 7;
    pt3.y = 15;
    pt3.next = &pt4;
    
    pt4.x =7
}