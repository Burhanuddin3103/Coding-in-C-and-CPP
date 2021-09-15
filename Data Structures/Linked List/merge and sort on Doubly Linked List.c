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

n *head1 = NULL;
n *head2 = NULL;

void printList(int listno)
{
   if(listno==1)
   {
   n *temp = head1;
   printf("\n");
   while(temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
   }
   if(listno==2)
   {
   n *temp = head2;
   printf("\n");
   while(temp != NULL)
    {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
   }
}

void sort (int listno)
{
    if(listno==1)
    {
    n *temp2=head1;
    n *second=head1;
    second = second->next;
    int d=0;
    while(second!=NULL)
    {
        if(temp2->data>second->data)
        {
            d = temp2->data;
            temp2->data = second->data;
            second->data = d;
        }
        temp2 = temp2->next;
        second = second->next;
    }
    }
    if(listno==2)
    {
    n *temp2=head2;
    n *second=head2;
    second = second->next;
    int d=0;
    while(second!=NULL)
    {
        if(temp2->data>second->data)
        {
            d = temp2->data;
            temp2->data = second->data;
            second->data = d;
        }
        temp2 = temp2->next;
        second = second->next;
    }
    }
}

void insertList(int data , int listno)
{
    if(listno==1)
    {
        n *NewNode = (n*)malloc(sizeof(n));
        NewNode->data= data;//copy data to new node
        n *temp = head1;
        if(head1==NULL)
        {
            NewNode->next = head1;
            head1 = NewNode;
        }
        else
        {
            while(temp->next != NULL)
                temp=temp->next;//while loop goes to last element of list
            temp->next=NewNode;//last element now points to new node
            NewNode->prev = temp;
            NewNode->next = NULL;//end pointer from new node as it is being added in the end
            sort(1);
        }
    }
    if(listno==2)
    {
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data= data;//copy data to new node
    n *temp = head2;
    if(head2==NULL)
    {
        NewNode->next = head2;
        head2 = NewNode;
    }
    else
    {
    while(temp->next != NULL)
        temp=temp->next;//while loop goes to last element of list
    temp->next=NewNode;//last element now points to new node
    NewNode->prev = temp;
    NewNode->next = NULL;//end pointer from new node as it is being added in the end
    sort(2);
    }
    }
}
void merge()
{
    n *temp2 = head2;
    while(temp2 != NULL)
    {
        insertList(temp2->data,1);
        temp2 = temp2->next;
    }
}

int main()
{
    insertList(2,1);
    insertList(1,1);
    insertList(3,1);
    printList(1);
    insertList(6,2);
    insertList(4,2);
    insertList(5,2);
    printList(2);
    merge();
    printList(1);
    return 0;
}
