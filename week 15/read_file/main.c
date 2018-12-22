#include <stdio.h>
#include <stdlib.h>
int data[50005];
int main()
{
    FILE*fin, *fout;
    int i, j, tmp;
    int num_data;

    fin = fopen("data_50000.txt", "r");//fopen("檔案路徑和檔名", "開檔方式")
    //open the file and get the address of the file
    fscanf(fin, "%d", &num_data);//fscanf(檔案指標, "讀取格式", 變數的位址);
    for (i=0; i<num_data; i++) {
        fscanf(fin, "%d", &data[i]);
    }
    fclose(fin);//after reading the file, close the file.
    for (i=1; i<num_data; i++) {
        j = i;
        tmp = data[j];
        while (j>0 && data[j-1]>tmp) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }

    fout = fopen("data_50000_out.txt", "w");
    for (i=0; i<num_data; i++)
        fprintf(fout, "%d ", data[i]);
    fclose(fout);
    return 0;
}
