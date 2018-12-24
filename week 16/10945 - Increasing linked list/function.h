#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void insert_increase_list(Node** head, int val)
{
    Node *newPtr, *previousPtr, *currentPtr;
    newPtr  = (Node*)malloc(sizeof(Node));

    if(newPtr==NULL) {
        printf("failed\n");
        return;
    }

    newPtr->data = val;
    newPtr->next = NULL;

    previousPtr = NULL;
    currentPtr = *head;

    while(currentPtr!=NULL && val>currentPtr->data) {
        previousPtr = currentPtr;//上一個要記住，因為找到以後要用上一個指標記住
        currentPtr = currentPtr->next;
    }
    if(previousPtr == NULL) {
        newPtr->next = *head;
        *head = newPtr;
    }//根本都沒開始走insert 位置在最前面

    else {
        previousPtr->next = newPtr;
        newPtr->next = currentPtr;
    }//insert in the middle
}
