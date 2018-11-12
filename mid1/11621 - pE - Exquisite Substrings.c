#include<stdio.h>
#include<string.h>
//#define OJ
int check(int len);
char s[2000];
int main()
{
    int len;

#ifndef OJ
    freopen("11621.txt", "r", stdin);
#endif // OJ
    while (scanf("%s", s)!=EOF) {
        len = strlen(s);
        printf("%d\n", check(len));
    }
}
int check(int len)
{
    int i,j;
    int k=0;
    int ans=0;
    int x,y;
    /* check the odd */
//    for (i=0; i+2<=len-1; i++) {
//        k=i;
//        for (j=i+2; j<=len-1; j++) {
//            if (s[k]==s[j]&&k>=0) {
//                k--;
//                ans++;
//            }
//            else break;
//        }
//    }
//    /* check the even */
//    for (i=0; i+1<=len-1; i++) {
//        k=i;
//        for (j=i+1; j<=len-1; j++) {
//            if (s[k]==s[j]&&k>=0) {
//                k--;
//                ans++;
//            }
//            else break;
//        }
//    }
//    printf("123\n");
    for (i=0; i<len; i++) {
        j = 0;
        x = i-j;
        y = i+j+1;
        while (x>=0&&y<len&&s[x]==s[y]) {
//            printf("11");
            ans++;
            j++;
            x = i-j;
            y = i+j+1;
        }
        j = 0;
        x = i-j-1;
        y = i+j+1;
        while (x>=0&&y<len&&s[x]==s[y]) {
//            printf("11");
            ans++;
            j++;
            x = i-j-1;
            y = i+j+1;
        }
    }

    return ans;
}

