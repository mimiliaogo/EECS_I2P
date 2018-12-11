#include<stdio.h>
#include<stdlib.h>

struct t_node{
    int data;
    struct t_node *nextPtr;
};
typedef struct t_node Node;

void printQueue(Node *currentPtr);
void enqueue(Node * * headPtr, Node * * tailPtr, int val);//從尾巴加
int dequeue(Node * * headPtr, Node * * tailPtr);//從頭拿掉

int main()
{
    Node *head, *tail;

    head = NULL;
    tail = NULL;

    enqueue(&head, &tail, 6);
    printQueue(head);
    enqueue(&head, &tail, 4);
    printQueue(head);
    enqueue(&head, &tail, 0);
    printQueue(head);
    enqueue(&head, &tail, 5);
    printQueue(head);

    printf("%d is out.\n", dequeue(&head, &tail) );
    printQueue(head);


    printf("%d is out.\n", dequeue(&head, &tail) );
    printQueue(head);


    return 0;
}

void printQueue(Node *currentPtr)
{
    if(currentPtr == NULL)
        printf("The stack is empty.\n");
    else{
        printf("Queue: \n");
        while(currentPtr != NULL){
            printf("%d--> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

void enqueue(Node * * headPtr, Node * * tailPtr, int val)
{
    Node * newPtr;
    newPtr = (Node *)malloc(sizeof(Node));
    if(newPtr == NULL){
        printf("Out of memory.\n");
    }
    else{
        newPtr->data = val;
        newPtr->nextPtr = NULL;
        if(*headPtr == NULL){
            *headPtr = newPtr;
            *tailPtr = newPtr;
        }else{
            (*tailPtr)->nextPtr = newPtr;
            *tailPtr = newPtr;
        }

    }
}

int dequeue(Node * * headPtr, Node * * tailPtr)
{
    int val;
    Node * tempPtr;

    if(*headPtr == NULL) return -1;

    val = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->nextPtr;

    if(*headPtr == NULL){
        *tailPtr = NULL;
    }
    free(tempPtr);

    return val;
}
