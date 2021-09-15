#include <stdio.h>
#include <stdlib.h>

int i;

typedef struct node n;
struct node
{
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

void InsertList(int data)
{
    i++;
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
        NewNode->next =NULL;
    }
}

void split()
{

    n *temp = head;
    int h=i/2 , r=i%2 , j;
    if(r==1)
        h=h+1;
    printf("\n\nfront half : ");
    for(j=0;j<h;j++)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("\n\nback half : ");
    for(j=j;j<i;j++)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    InsertList(1);
    InsertList(2);
    InsertList(3);
    InsertList(4);
    InsertList(5);
    InsertList(6);
    InsertList(7);
    printList();
    split();
    return 0;
}
