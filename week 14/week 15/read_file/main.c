#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE*fin, *fout;
    int i, j, tmp;
    int num_data;
    int *data;
    fin = fopen("data_50000.txt", "r");
    fscanf(fin, "%d", &num_data);
    for (i=0; i<num_data; i++) {
        fscanf(fin, "%d", &data[i]);
    }
    fclose(fin);
    for (i=1; i<num_data; i++) {
        j = i;
        tmp = data[j];
        while (j>0 && data[j-1]>tmp) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }
    fout = fopen("dara_50000_out.txt", "w");
    for (i=0; i<num_data; i++)
        fprintf(fout, "%d ", data[i]);
    fclose(fout);
    return 0;
}