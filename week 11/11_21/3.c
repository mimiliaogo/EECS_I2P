/* write a function of calculating the length of a string*/
/*when sending data, it sends the address, not the content.
so c,c++ have the fastest speed*/
/* there are several ways to write the len function*/
/*write a function of sum*/
/*
a+i ---> &a[i] --->& *(a+i) ---> a+i
*(a+i) <--- a[i]
*/
#include <stdio.h>

unsigned int mylen1(char * );
unsigned int mylen2(char * );
unsigned int mylen3(char * );
int sum(int * , int n);
int main()
{
    char str[100];
    int a[100];
    int i, n;
    //len
//    scanf("%s", str);
//    printf("%u\n", mylen2(str));
    //sum
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d\n",a+i);//a[i]
    }
    printf("%d\n", sum(a, n));

    return 0;
}

unsigned int mylen1(char * cp)
{
    unsigned int len = 0;
    while ( *cp != '\0') {
        cp++;
        len++;
    }

    return len;
}
unsigned int mylen2(char * str)//char str[]
{
    unsigned int len = 0;
    while (str[len] != '\0') { // *(cp+len) cp[len]  *(len+cp) len[cp]
        len ++;
    }
    return len;

}

unsigned int mylen3(char * cp)
{
    char * startp;
    startp = cp;//copy one memory address to another pointer
     while ( *cp != '\0') {
        cp++;
    }
    return cp-startp;
}

int sum(int *ap, int sz)
{
    int ans = 0;
    while (sz>0) {
        ans = ans + *ap;
        ap++;
        sz--;
    }
    return ans;
}
