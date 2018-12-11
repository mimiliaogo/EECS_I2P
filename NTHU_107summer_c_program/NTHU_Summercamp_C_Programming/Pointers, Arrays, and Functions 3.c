#include<stdio.h>
int bsearch(int a[], int left, int rifgt, int key);

int main()
{
    int a[] = {1,1,2,3,5,8,13,21,34,55};
    int key;
    int index;



    scanf("%d", &key);

    index = bsearch(a, 0, sizeof(a)/sizeof(int)-1, key);

    if(index < 0)
        printf("Not found");

    else
        printf("[%d]: %d\n", index, a[index]);


    return 0;
}

int bsearch(int a[], int left, int right, int key)
{
    int mid;

    if(left>right)
        return -1;

    mid = left + (right-left)/2;

    if(a[mid]==key){
        return mid;
    }else if(key < a[mid]){
        return bsearch(a, left, mid-1, key);
    }else {
        return bsearch(a, mid+1, right, key);
    }


}
