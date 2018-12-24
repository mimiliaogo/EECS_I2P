#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
} Point;
Point * pts_vec(int N)
{
    Point * p;
    p = (Point *) malloc(sizeof(Point)*N);
    return p;//illegal to return &p
}
void pts_free(Point* p)
{
    free(p);
}
void pts_vec2(int N, Point ** pp)
{
    *pp = (Point *) malloc(sizeof(Point)*N);
}
int main()
{
    int i; 
    Point *pts;

    pts = pts_vec(100);
    pts_vec2(100, &pts);

    for (i=0; i<100; i++) {
        pts[i].x = i*5;
        pts[i].y = i*10;
    }
    pts_free(pts);
}