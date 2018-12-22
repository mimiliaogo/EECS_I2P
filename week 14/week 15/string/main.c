#include <stdio.h>
#include <string.h>
int main()
{
    // produce a legal string
    /*str1="asd"  str1 = {'a','s','\0'} */
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strncmp(str1, str2, 3));//比前三個
    
    strcpy(str2, str1);//latter copy to former
    strncpy(str2, str1, 3);
    strcat(str2, str1);//latter combine to the former
    printf("%s\n", str2);
}