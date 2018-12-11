#include<stdio.h>

struct t_point {
    int x;
    int y;
};
typedef struct t_point Point;
struct t_rect{;

    Point pt1;
    Point pt2;

};
typedef struct t_rect Rect;

int area(Rect * rect);
int main()
{
    Rect rect1 = {{10, 20}, {50, 60}};/*struct t_rect */
    Rect rect2;
    Rect rect_array[100];

    rect2 = rect1;

    printf("pt1.x=%d, pt1.y=%d\n", rect2.pt1.x, rect2.pt1.y);
    printf("pt2.x=%d, pt2.y=%d\n", rect2.pt2.x, rect2.pt2.y);

    printf("%d", area(&rect2));

    return 0;
}

int area(Rect * rect)
{
    return((*rect).pt2.x - (*rect).pt1.x) * ((*rect).pt2.y - (*rect).pt1.y);
    //可寫為 ｒｅｃｔ->pt2.x
}
