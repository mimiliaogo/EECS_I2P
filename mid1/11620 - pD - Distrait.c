#include <stdio.h>
int row[26];
int col[26];
int sloper[26] = {0};
int slople[26] = {0};
int bingo[13] = {0};

int findbingo(int t);
int main()
{
#ifndef OJ
    freopen("11620.txt", "r", stdin);
#endif // OJ
    int map;
    int n;
    int t;
    int i,j,k;
    int ans;
    for (i=1; i<=5; i++) {
        for (j=1; j<=5; j++) {
            scanf("%d", &map);
            row[map] = i;
            col[map] = j+5;
            if (i==j) sloper[map] = 11;
            if (i+j==6) slople[map] = 12;
        }
    }
    scanf("%d", &n);
    j = n;
    while (n>0) {
        scanf("%d", &t);
        for (i=0; i<13; i++) {
            bingo[i] = 0;
        }
        ans = findbingo(t);
        if (ans==100) {
            printf("Case #%d: Not yet \\(^o^)/\n", j-n+1);
        }
        else printf("Case #%d: %d\n", j-n+1,ans);
        n--;
    }
}
int findbingo(int t)
{
    int pick;
    int th;
    int isbingo;
    int k;
    th = 1;
    isbingo = 0;
    while (t>0) {
        scanf("%d", &pick);
        bingo[row[pick]]++;
        bingo[col[pick]]++;
        bingo[sloper[pick]]++;
        bingo[slople[pick]]++;
        bingo[0] = 0;

        if ((bingo[row[pick]]==5||bingo[col[pick]]==5||bingo[sloper[pick]]==5||bingo[slople[pick]]==5)&&isbingo==0)
        {
            isbingo = 1;
        }
        t--;
        if(isbingo==0) th++;
    }
    if (isbingo) return th;
    else return 100;

}
