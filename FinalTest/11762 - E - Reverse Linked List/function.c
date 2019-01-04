#include "function.h"

Node* Create_List(Node* head, int val)
{
    Node *newptr, *preptr, *curptr;
    newptr = (Node*)malloc(sizeof(Node));

    newptr->data = val;
    newptr->next = NULL;

    preptr = NULL;
    curptr = head;

    while(curptr!=NULL) {
        preptr = curptr;
        curptr = curptr->next;
    }
    if (preptr==NULL) {
        newptr->next = head;
        head = newptr;
    }

    else {
        preptr->next = newptr;
        newptr->next = curptr;
    }
    return head;
}
Node* Reverse_List(Node* head)
{
    Node *curptr, *preptr, *nxtptr;
    preptr = NULL;
    curptr = head;
    nxtptr = curptr->next;
    while (curptr!=NULL) {
        nxtptr = curptr->next;
        curptr->next = preptr;
        preptr = curptr;
        curptr = nxtptr;
    }
    head = preptr;
    return head;
}
void Print_List(Node* head)
{
    Node *temp;
	for(temp = head; temp->next!=NULL; temp=temp->next)
	{
		printf("%d->", temp->data);
	}
	printf("%d", temp->data);
	printf("\n");

}
void Free_List(Node* head)
{
    Node *temp;

    for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}

}
