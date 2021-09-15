#include <stdio.h>
#include <stdlib.h>

typedef struct node n;
struct node
{
   struct node *prev;
   int data;
   int key;
   struct node *next;
};

n *head = NULL;

void printList()
{
   n *temp = head;
   printf("\n");
   while(temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
}

void Push(int data)
{
   n *NewNode = (n*) malloc(sizeof(n));
   NewNode->data = data;//copy data in new node
   n *temp = head;
   NewNode->prev = NULL;
   NewNode->next = head;
   if(head != NULL)
    head->prev = NewNode;
   head = NewNode;
}

void Pop()
{
    if(head==NULL)
        printf("list is empty");
    else
    {
        n *temp = head;//copy head in temp
        head = head->next;//shift head ahead
        free(temp);//free first element stored in temp
        head->prev=NULL;
    }
}

int main()
{
    Push(1);
    Push(2);
    printList();
    Pop();
    Push(3);
    printList();
    return 0;
}
