#include<stdio.h>
#include<stdlib.h>

struct queue
{
int que[100];
int top;
}q;

void push(int item)
{
int i,temp=0;
q.top++;
q.que[q.top] = item;
for(i=q.top;i>0;i--)
{
    if(q.que[i]<=q.que[i-1])
    {
        temp=q.que[i];
        q.que[i]=q.que[i-1];
        q.que[i-1]=temp;
    }
}
}

void pop()
{
int i;
for(i=0;i<q.top;i++)
    q.que[i]=q.que[i+1];
q.top--;
}

int main()
{
    q.top=-1;
    int x,i=0;
    do
    {
    printf("\n\n1.Add new passenger\n2.Remove passenger from the front of the queue\n3.Display next passenger in the queue\n4.Exit\nEnter your choice : ");
    scanf("%d",&x);
    switch(x)
    {

case 1:
    {
        i++;
        push(i);
        printf("\n\nnew passenger added in the queue");
        break;
    }
case 2:
    {
        if(q.top!=-1)
        {
            pop();
            printf("\n\npassenger at the front of the queue removed");
        }
        else
            printf("\n\nqueue is empty");
        break;
    }
case 3:
    {
        if(q.top!=-1)
            printf("\n\nthe next passenger in the queue is : passenger %d",q.que[0]);
        else
            printf("\n\nqueue is empty");
        break;
    }
case 4:
    break;
default:
    printf("\n\ninvalid choice");
    break;
    }
    }while(x!=4);
    printf("\n\npassengers left in the queue : %d",q.top+1);
    return 0;
}
