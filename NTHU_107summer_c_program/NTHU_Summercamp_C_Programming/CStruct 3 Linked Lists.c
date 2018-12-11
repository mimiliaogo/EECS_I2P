#include<stdio.h>
#include<stdlib.h>
/*pictures illustrated in clip */
struct t_node{
    int data;
    struct t_node *nextPtr;//指向自己的指標
};

typedef struct t_node Node;

Node * insertList(Node *np, int val);
Node * deleteList(Node *np, int val);
void dispList(Node *np);//顯示linked list的函數

int main(void){
    Node * head;
    head = NULL;


    head = insertList(head, 4);
    dispList(head);

    head = insertList(head, 15);
    dispList(head);

    head = insertList(head, 0);
    dispList(head);

    head = deleteList(head, 15);
    dispList(head);


    return 0;
}

void dispList(Node *np)
{

    if(np == NULL){
        printf("List is empty.\n\n");
    }
    else{
        printf("Linked list: \n");
        while(np != NULL){
            printf("%d-->", np->data);
            np = np->nextPtr;
        }
        printf("NULL\n\n");
    }
}

Node * insertList(Node *np, int val)
{
    Node *newPtr, *previousPtr, *currentPtr;

    newPtr = (Node *)malloc(sizeof(Node));

    if(newPtr == NULL){
        printf("Out of memory.\n");
        return NULL;
    }
    newPtr->data = val;
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = np;

    while(currentPtr!=NULL && val>currentPtr->data){  //還沒走到結尾並且還沒找到該放的位置
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if(previousPtr == NULL){
        newPtr->nextPtr = np;
        np = newPtr;
    }
    else {
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
    return np;
}

Node * deleteList(Node *np, int val)
{
    Node *previousPtr, *currentPtr, *tempPtr;

    if(val==np->data){
        tempPtr = np;
        np = np->nextPtr;
        free(tempPtr);
        return np;
    }

    previousPtr = np;
    currentPtr = np->nextPtr;
    while(currentPtr!=NULL && currentPtr->data<val){
        previousPtr = currentPtr;
        currentPtr = previousPtr->nextPtr;
    }
    if(currentPtr!=NULL ) {
        if(currentPtr->data==val){
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
        }

    }
    return np;
}
