#include<stdio.h>


int main(void){
    double x = 123.45;
    int width, precition;
    scanf("%d%d",&width,&precition);
    printf("%12.2f\n",x);
    printf("%*.*f",width,precition,x);

    char word[46];


    scanf("%45s",word);//限制最多45個因為最後是'0'
    printf("%.4s\n",word);//只顯示出前面四個字元
    printf("%10.4s\n",word);//要顯示出寬度十個字元，只顯示出前面的字元
    printf("%-10.4s\n",word);


      int len;
      scanf("%45s%n",word,&len);
      printf("%*.*f",len,len/2,word);

}
