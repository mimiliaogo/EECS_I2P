#include<stdio.h>
/*二進位表示法*/
void dispBit(unsigned int val);

int main()
{
    unsigned int n;
    n = 9;
    printf("     ");
    dispBits(n); //整數值的二進位表示法顯示出來

    printf("     ");
    dispBits(0x1f);

    printf("--------------------------\n");
    printf("AND  ");
    dispBits(n & 0x1f);
    printf("OR   ");
    dispBits(n | 0x1f);
    printf("XOR  ");
    dispBits(n ^ 0x1f);
    printf("1's  ");
    dispBits( ~n );

    return 0;
}

void dispBits(unsigned int val)
{
    unsigned int mask = 1 << 31;// 1後面接31個0 。一個整數的最高位數
    int i;
    for(i=0; i<32; i++){
        printf("%d", (mask&val) != 0);//非零顯現出一
        /*
        100
        110
        ->100
        */
        mask = mask >> 1;
    }
    printf("\n");
}
