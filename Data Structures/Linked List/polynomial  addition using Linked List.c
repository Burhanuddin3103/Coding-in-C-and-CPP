#include <stdio.h>
#include <stdlib.h>

typedef struct node n;
struct node
{
   int coeff;
   int power;
   struct node *next;
};

n *head1 = NULL;
n *head2 = NULL;
n *head = NULL;

void printList(int listno)
{
    if(listno==1)
    {
        n *temp = head1;
        printf("\n");
        while(temp != NULL)
        {
            printf("%dx^%d + ",temp->coeff,temp->power);
            temp = temp->next;
        }
    }
    if(listno==2)
    {
        n *temp = head2;
        printf("\n");
        while(temp != NULL)
        {
            printf("%dx^%d + ",temp->coeff,temp->power);
            temp = temp->next;
        }
    }
    if(listno==3)
    {
        n *temp = head;
        printf("\n");
        while(temp != NULL)
        {
            printf("%dx^%d + ",temp->coeff,temp->power);
            temp = temp->next;
        }
    }
}

void sort ()
{
    n *temp = head;
    while(temp != NULL)
    {
        n *second = head;
        while(second != NULL && temp !=second)
        {
            int d1=0,d2=0;
            if(temp->power > second->power)
            {
                d1 = temp->power;
                d2 = temp->coeff;
                temp->power = second->power;
                temp->coeff = second->coeff;
                second->power = d1;
                second->coeff = d2;
            }
            second = second->next;
        }
        temp = temp->next;
    }
}

void add(int t1 , int t2)
{
    int i=0;
    printf("\n\nFor Polynomial 1 :");
    for(i=0;i<t1;i++)
    {
        n *Poly1 = (n*) malloc(sizeof(n));
        printf("\nEnter the coefficient of term %d :",i+1);
        scanf("%d",&Poly1->coeff);
        printf("\nEnter the power of term %d :",i+1);
        scanf("%d",&Poly1->power);
        n *temp = head1;
        if(head1 == NULL)
        {
            Poly1->next = head1;
            head1 = Poly1;
        }
        else
        {
            while(temp->next != NULL)
                temp = temp->next;//while loop goes to last element of list
            temp->next = Poly1;//last element now points to new node
            Poly1->next = NULL;
        }
    }
    printf("\n\nPolynomial 1 :");
    printList(1);
    printf("\n\nFor Polynomial 2 :");
    for(i=0;i<t2;i++)
    {
        n *Poly2 = (n*) malloc(sizeof(n));
        printf("\nEnter the coefficient of term %d :",i+1);
        scanf("%d",&Poly2->coeff);
        printf("\nEnter the power of term %d :",i+1);
        scanf("%d",&Poly2->power);
        n *temp = head2;
        if(head2 == NULL)
        {
            Poly2->next = head2;
            head2 = Poly2;
        }
        else
        {
            while(temp->next != NULL)
                temp=temp->next;//while loop goes to last element of list
            temp->next=Poly2;//last element now points to new node
            Poly2->next = NULL;
        }
    }
    printf("\n\nPolynomial 2 :");
    printList(2);

    n *temp1 = head1;
    n *temp2 = head2;

    while(temp1 != NULL && temp2 != NULL)
    {
        n *Poly = (n*) malloc(sizeof(n));
        if(temp1->power > temp2->power)
        {
            Poly->power = temp1->power;
            Poly->coeff = temp1->coeff;
            temp1 = temp1->next;
        }
        else if(temp2->power > temp1->power)
        {
            Poly->power = temp2->power;
            Poly->coeff = temp2->coeff;
            temp2 = temp2->next;
        }
        else if(temp1->power == temp2->power)
        {
            Poly->power = temp1->power;
            Poly->coeff = temp1->coeff + temp2->coeff;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(head == NULL)
        {
            Poly->next = head;
            head = Poly;
        }
        else
        {
            n *temp = head;
            while(temp->next != NULL)
                temp=temp->next;//while loop goes to last element of list
            temp->next=Poly;//last element now points to new node
            Poly->next = NULL;
        }
    }
    while(temp1 != NULL || temp2 != NULL)
    {
        n *Poly = (n*) malloc(sizeof(n));
        if(temp1 != NULL)
        {
            Poly->power = temp1->power;
            Poly->coeff = temp1->coeff;
            temp1 = temp1->next;
        }
        if(temp2 != NULL)
        {
            Poly->power = temp2->power;
            Poly->coeff = temp2->coeff;
            temp2 = temp2->next;
        }
        if(head == NULL)
        {
            Poly->next = head;
            head = Poly;
        }
        else
        {
            n *temp = head;
            while(temp->next != NULL)
                temp=temp->next;//while loop goes to last element of list
            temp->next=Poly;//last element now points to new node
            Poly->next = NULL;
        }
    }
    sort();
    printf("\n\nRequired Polynomial :");
    printList(3);
}

int main()
{
    int t1 =0 ,t2 = 0;
    printf("Enter the number of terms of polynomial 1 : ");
    scanf("%d",&t1);
    printf("Enter the number of terms of polynomial 2 : ");
    scanf("%d",&t2);
    add(t1,t2);
    return 0;
}
