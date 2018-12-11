#include<stdio.h>
/* 取出x的第p位置算起n個bits */
unsigned int getBits(unsigned int x, int p, int n);

/* 把x第p位置算起n個bits由0變1，1則變為0 */
unsigned int invert(unsigned int x, int p, int n);

/* 傳回x向右rotate n bits之後的結果 */
unsigned rightRotate(unsigned int x, int n);

void dispBit(unsigned int val);

int main()
{
    unsigned int n;
    n = 103;
    dispBits(n); //整數值的二進位表示法顯示出來
    dispBits( getBits(n, 4, 3) );
    dispBits( invert(n, 3, 3) );
    dispBits( rightRotate(n, 5) );




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

unsigned int getBits(unsigned int x, int p, int n)
{
    return ( x>>(p-n) ) & ~( ~0<<n );//~( ~0<<n ) ;
}

unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ ~( ~0<<n ) << (p-n);
    /* XOR 0--->1
           1

           1--->0
           1
    */
}

unsigned rightRotate(unsigned int x, int n)
{
    return ((x & ~( ~0<<n )) << (sizeof(x)*8 - n) )|(x>>n);

}
