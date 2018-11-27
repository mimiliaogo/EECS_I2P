#include <stdio.h>
#include <ctype.h>

int calculate();
int main()
{
    int ans;
    ans = calculate();
    printf("=");
    printf("%d\n", ans);
    return 0;
}

int calculate()
{
    char c;
    int ans, A, B;
    c = getchar();
    if (isspace(c)) ans = calculate();//continue to call function {
    else if (c=='+') {
        printf("(");
        A = calculate();
        printf("+");
        B = calculate();
        printf(")");
        ans = A+B;
    } else if (c=='-') {
        printf("(");
        A = calculate();
        printf("-");
        B = calculate();
        printf(")");
        ans = A-B;
    } else if (c=='*') {
        printf("(");
        A = calculate();
        printf("*");
        B = calculate();
        printf(")");
        ans = A*B;
    } else if (c=='/') {
        printf("(");
        A = calculate();
        printf("/");
        B = calculate();
        printf(")");
        ans = A/B;
    } else if (isdigit(c)){
        ungetc(c, stdin);
        scanf("%d", &ans);
        printf("%d", ans);
    }
    else ans = 0;
    return ans;
}
