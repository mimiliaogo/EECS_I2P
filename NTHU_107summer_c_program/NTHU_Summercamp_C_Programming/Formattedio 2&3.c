#include<stdio.h>


int main(void){
    double x = 123.45;
    int width, precition;
    scanf("%d%d",&width,&precition);
    printf("%12.2f\n",x);
    printf("%*.*f",width,precition,x);

    char word[46];


    scanf("%45s",word);//����̦h45�Ӧ]���̫�O'0'
    printf("%.4s\n",word);//�u��ܥX�e���|�Ӧr��
    printf("%10.4s\n",word);//�n��ܥX�e�פQ�Ӧr���A�u��ܥX�e�����r��
    printf("%-10.4s\n",word);


      int len;
      scanf("%45s%n",word,&len);
      printf("%*.*f",len,len/2,word);

}
