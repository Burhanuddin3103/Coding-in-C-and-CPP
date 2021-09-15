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
    int x,i,n,r,arr[100];
    printf("enter the length of the queue : ");
    scanf("%d",&n);
    printf("\n\nenter the elements of the queue : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        push(arr[i]);
    }
    printf("\n\nenter the element to be replaced : ");
    scanf("%d",&r);
    printf("\n\nenter the element of the queue that is to be replaced :");
    scanf("%d",&x);
    printf("\n\nthe new queue is :");
    while(q.top!=-1)
    {
        if(q.que[0]==x)
            q.que[0]=r;
        printf("%d",q.que[0]);
        pop();
    }
    return 0;
}
