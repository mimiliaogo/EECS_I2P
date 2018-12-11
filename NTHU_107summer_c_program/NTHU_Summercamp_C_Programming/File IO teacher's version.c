#include <stdio.h>
#include <stdlib.h> /* 為了用srand() 和rand() */
#include <time.h> /* 為了用time() 產生亂數種子*/
#define LINE_LEN 40 /* 假設單字長度不超過40 個字元*/
#define NUM_WORDS 5000 /* 總共有5000 個單字*/
char dictionary[NUM_WORDS][LINE_LEN]; /* 儲存單字的陣列每個 row 都是一個字串儲存一個單字 */
int main(void)
{
FILE *fp; /* 開檔案需要一個指標指到開啟的檔案 */
int nw;
int i;
/* fopen() 的用法就是傳入檔名字串以及開檔方式 "r" 表示只要讀檔*/
/* fopen() 會傳回指到檔案的指標失敗的話那個指標會是 NULL 表示沒有指到任何地方*/
if ( (fp = fopen("5000_words.txt", "r")) == NULL ) {
printf("Cannot open file.\n");
exit(1);
}
/*
用fscanf() 把所有的單字都讀進來
fscanf() 和scanf() 的用法相同
只是要多傳一個參數把檔案指標傳給 fscanf()
才能夠知道是要從哪個檔案讀資料
feof(fp) 可以判斷檔案fp 是否已經讀到了盡頭
如果已經到了檔案結尾feof(fp) 會傳回true
fgetc(fp) 則只會讀取一個字元我們只想讀取單字
所以用fgetc(fp) 把剩下的單字解釋略過一直讀到換行 再繼續讀下個單字
*/
nw = 0;
while (!feof(fp) && nw < NUM_WORDS) {
fscanf(fp, "%s", dictionary[nw]);
while ( !feof(fp) && fgetc(fp) != '\n' ) ;
nw++;
}
fclose(fp);
/*
隨機選10 個單字出來
dictionary[][] 的每一個row 都是一個字串
例如dictionary[1002] 儲存的是"convertible" 這個字串
所以dictionary[1002][0] 就是'c' 而dictionary[1002][1] 就是'o'
以此類推dictionary[1002][10] 是'e' 然後dictionary[1002][11] 是'\0'
*/
srand(time(NULL));
for (i=0; i<10; i++) {
printf("%s\n", dictionary[rand()%NUM_WORDS]);
}
return 0;
}
