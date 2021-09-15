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

void Enqueue(int data)
{
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data= data;//copy data to new node
    n *temp = head;
    if(head == NULL)
    {
        NewNode->next = head;
        head = NewNode;
    }
    else
    {
        while(temp->next != NULL)
            temp=temp->next;//while loop goes to last element of list
        temp->next=NewNode;//last element now points to new node
        NewNode->prev = temp;
        NewNode->next = NULL;//end pointer from new node as it is being added in the end
    }
}

void Dequeue()
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
    Enqueue(1);
    Enqueue(2);
    printList();
    Dequeue();
    printList();
    return 0;
}
