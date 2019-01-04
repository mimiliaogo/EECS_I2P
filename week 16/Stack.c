#include <stdio.h>
#include <stdlib.h>
typedef struct t_node {
    int val;
    struct t_node *next;//Node haven't appeared,and it should only be pointer(fixed size)
} Node;
//放上去
void push(Node ** hp, int v) //hp = &head *hp = head
{
    Node *p;
    p = (Node*) malloc(sizeof(Node));
    p->next = NULL;
    p->val = v;
    if (*hp==NULL) { //前面沒東西
        *hp = p;//改了外面的head
    }
    else { //前面有東西了
        p->next = *hp;
        *hp = p;
    }
}
int pop(Node **hp)
{
    Node *p;
    int x;
    if (*hp == NULL) return 0;
    else {
        p = *hp;
        *hp = p->next;
        x = p->val;
        free(p);
    }
    return x;
}
void show(Node *h)
{
    while (h !=NULL) {
        printf("%d->", h->val);
        h = h->next;
    }
    printf(".\n");
}

int main(void)
{
    int x;
    Node *head = NULL;//point to the start
    push(&head, 7);//give it the address of head 直接改值
    //另一種寫法為 head = push(head, 7) 則為傳指標回來
    push(&head, 6);
    push(&head, 5);
    push(&head, 7);
    show(head);

    x = pop(&head);
    printf("%d\n", x);
    x = pop(&head);
    printf("%d\n", x);
    show(head);

}
