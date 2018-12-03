#include <stdio.h>

float cal();
int main()
{
    printf("%.3f", cal());
    return 0;
}
float cal()
{
    char c;
    float op1, op2;
    c = getchar();
    if (c=='+') {
        op1 = cal();
        op2 = cal();
        return op1+op2;
    }
    else if (c=='-') {
        op1 = cal();
        op2 = cal();
        return op1-op2;
    }
    else if (c=='*') {
        op1 = cal();
        op2 = cal();
        return op1*op2;
    }
    else if (c=='/') {
        op1 = cal();
        op2 = cal();
        return op1/op2;
    }
    else if (isdigit(c)) {
        return c-'0';
    }
    else if (c=='=') {
        return;
    }
}
