#include <stdio.h>
int lens, lent;
int count;
char s[25];
char t[25];
void search(int curt, int curs)
{
    int i;
    i = curt;
    if (curs==lens) count++;
    else {
        while (lent-i>=lens-curs) {
            if(t[i]==s[curs]) search(i+1, curs+1);
            i++;
        }

    }

}
int main()
{
    int i;
    while ( scanf("%s", t)!=EOF) {
        scanf("%s", s);
        lent = strlen(t);
        lens = strlen(s);
        search(0, 0);
        printf("%d\n", count);
        count = 0;
    }


    return 0;
}
