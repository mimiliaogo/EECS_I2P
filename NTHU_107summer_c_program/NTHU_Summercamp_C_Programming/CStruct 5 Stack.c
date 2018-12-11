#include<stdio.h>
#include<stdlib.h>

struct t_node {
    int data;
    struct t_node *nextPtr;
};
typedef struct t_node Node;

void printStack(Node *);
void push(Node * * topPtr,int val); //put //指標變數的記憶體位置
int pop(Node * * topPtrPtr); //remove


int main()
{
    Node * stackPtr = NULL;

    push(&stackPtr, 8);
    printStack(stackPtr);
    push(&stackPtr, 3);
    printStack(stackPtr);
    push(&stackPtr, 15);
    printStack(stackPtr);
    push(&stackPtr, 23);
    printStack(stackPtr);
    push(&stackPtr, 42);
    printStack(stackPtr);


    printf("%d is popped.\n", pop(&stackPtr));
    printStack(stackPtr);
    printf("%d is popped.\n", pop(&stackPtr));
    printStack(stackPtr);
    printf("%d is popped.\n", pop(&stackPtr));
    printStack(stackPtr);
    printf("%d is popped.\n", pop(&stackPtr));
    printStack(stackPtr);

    return 0;
}


void printStack(Node *currentPtr)
{
    if(currentPtr == NULL)
        printf("The stack is empty.\n");
    else{
        printf("Stack: \n");
        while(currentPtr != NULL){
            printf("%d--> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

void push(Node * * topPtrPtr,int val)
{
    Node * newPtr;
    newPtr = (Node *)malloc(sizeof(Node));
    if(newPtr == NULL){
        printf("Out of memory.\n");
    }
    else{
        newPtr->data = val;
        newPtr->nextPtr =  *topPtrPtr; /* StackPtr */
        *topPtrPtr = newPtr;

    }
}

int pop(Node * * topPtrPtr)
{
    Node * tempPtr;
    int popValue;

    if(*topPtrPtr ==NULL)return -1;

    tempPtr = *topPtrPtr;
    *topPtrPtr = (*topPtrPtr)->nextPtr;
    popValue = tempPtr->data;
    free(tempPtr);
    return popValue;
}

