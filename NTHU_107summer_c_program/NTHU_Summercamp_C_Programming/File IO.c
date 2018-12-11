#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> // time()
#define LINE_LEN 40 //單字長度不超過40
#define NUM_WORDS 5000
char dictionary[NUM_WORDS][LINE_LEN];


int main()
{

    FILE * fp;
    int nw;
    int i;
    if((fp = fopen("5000_words.txt", "r")) == NULL) {
        /* 傳進要開啟的檔案名稱 r代表要讀檔(w 代表要寫檔) */
        printf("Cannot open file.\n");
        exit(1);//提前讓程式結束
    }
    nw = 0;
    while(!feof(fp) && nw<NUM_WORDS) {
        //feof decides whether it's the end if true -> 1
        fscanf(fp, "%s", dictionary[nw]);
        while(!feof(fp) && fgetc(fp)!='\n') ;//讓他不斷讀取直到讀到換行字元
        nw++;
    }
    fclose(fp);

    srand(time(NULL));
    for(i=0; i<10; i++) {
        printf("%s\n", dictionary[rand()%NUM_WORDS]);
    }


    return 0;

}
