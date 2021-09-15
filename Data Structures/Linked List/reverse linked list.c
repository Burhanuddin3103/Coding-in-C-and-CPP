#include <stdio.h>
#include <stdlib.h>

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

void insertFirst(int data)
{
   n *NewNode = (n*) malloc(sizeof(n));
   NewNode->data = data;//copy data in new node
   NewNode->next = head;//link new node to the front of head
   head = NewNode;//assign head to new node so head is now first element
}

void deleteFirst()
{
    if(head==NULL)
        printf("list is empty");
    else
    {
        n *temp = head;//copy head in temp
        head = head->next;//shift head ahead
        free(temp);//free first element stored in temp
    }
}


void insertLast(int data)
{
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data= data;//copy data to new node
    NewNode->next = NULL;//end pointer from new node as it is being added in the end
    n *temp = head;
    if(head == NULL)
    {
        NewNode->next = head;//link new node to the front of head
        head = NewNode;
    }
    else
    {
    while(temp->next != NULL)
        temp=temp->next;//while loop goes to last element of list
    temp->next=NewNode;//last element now points to new node
    }
}

void deleteLast()
{
    if(head==NULL)
        printf("list is empty");
    else
    {
        n* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;//while loop goes to second last position in list
        free(temp->next);//last element is freed
        temp->next = NULL;//new last element now points to null
    }
}

void insertAfter(int data,int location)
{
    n* NewNode = (n*) malloc(sizeof(n));
    NewNode->data=data;//copy data to new node
    n* temp = head;
    n* secondLast = head;
    while(temp->data!=location)
    {
        temp=temp->next;//while loop reaches required location after which node is to be added
        secondLast=temp;//second last is required location
    }
    temp=temp->next;//temp reaches next node of list
    secondLast->next=NewNode;//required position now linked to new node
    NewNode->next=temp;//new node now linked to its next element in list
}

void deleteMiddle(int data)
{
    if(head==NULL)
        printf("list is empty");
    else
    {
        n* temp = head;
        n* secondLast = head;
        while(temp->data!=data)
        {
            secondLast=temp;//while loop reaches element to be removed
            temp=temp->next;//temp refers to element to be removed     second last refers to element before that
        }
        free(temp);//element is deleted
        secondLast->next=temp->next;//second last now linked to element after the removed one
    }
}

void reverselist()
{
    n *Prev = NULL;
    n *Current = head;
    n *Next = NULL;
    while(Current != NULL)
    {
        Next = Current->next;
        Current->next = Prev;
        Prev = Current;
        Current = Next;
    }
    head = Prev;
}

int main()
{
    insertFirst(1);
    insertFirst(2);
    insertFirst(3);
    insertLast(4);
    insertLast(5);
    insertLast(6);
    insertAfter(7,4);
    printList();
    reverselist();
    printList();
    deleteFirst();
    deleteLast();
    deleteMiddle(1);
    printList();
    reverselist();
    printList();
    return 0;
}
