#include <stdio.h>
char str[100];
int a[100];
int main()
{
    char * address;
    int * ap;
    /* a pointer (pointer variable) is a variable that stores an address*/
    //scanf("%s", str);//name of an array = memory address
    printf("%p\n", str);//%p use to show memory address
    scanf("%s", str);
    address = str;
    printf("%p\n", address);
    ap = a;
    printf("%p\n", ap);

    *address = 'A'; /* (*address)like key to open the door,
    the space inside is a char space */
    *ap = 12345; /*== a[0] = 5984794*/
    printf("%c\n", str[0]);
    printf("%d\n", a[0]);


    *(address+3) = 'C';//address is a variable
    /* jump 3 spaces and take a key(*) to open the door */
    address  = address + 3;
    *(address) = 'C';
    /*the above equals to this */
    *(address-3) = 'W';

    /* address is a variable to memorize a memory address so it can change.
    but you can't write -- str = str + 3  cuz str is the unchanged address of the
    array str */
    printf("p: %p p-3: %p\n", address, address-3);
    printf("p: %p p+3: %p\n", ap, ap+3);
    /* one char space == 1 byte, one int space == 4 */
    printf("%c\n", address[-3]);//==str[0]
    printf("%d\n", ap[0]);
    /* replace the original name of array with pointer variables */
    printf("%c\n", *(address-3)); //the above equals to this


    ap+=5;
    printf("%d %d %d %d \n", ap[-5],*(ap-5), *(-5+ap), (-5)[ap] );
}
