#include <stdio.h>
float cal4(char c, int x, int y)
{
    if (c=='+') {
        return x+y;
    }
    else if (c=='-') {
        return x-y;
    }
    else if (c=='*') {
        return x*y;
    }
    else if (c=='/') {
        return x/y;
    }
}
int isop(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/');
}
float cal()
{
    char c;
    float x, y, z;
    c = getchar();
    if (c=='(') {
        x = cal();
        c = getchar();
        y = cal();
        z = cal4(c, x, y);
        getchar();
        return z;
    }
    else if (isdigit(c)) {
        return c-'0';
    }
    else if (isop(c)) {
        return c;
    }
    else return ;


}
int main()
{
    printf("%g", cal());
    return 0;
}


