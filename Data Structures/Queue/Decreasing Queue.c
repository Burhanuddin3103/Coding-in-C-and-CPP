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
    if(q.que[i]>=q.que[i-1])
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
for(i=0;i<=q.top;i++)
    q.que[i]=q.que[i+1];
q.top--;
}

int main()
{
    q.top=-1;
    int i,n,arr[100];
    printf("enter the number of elements of the array : ");
    scanf("%d",&n);
    printf("enter the elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        push(arr[i]);
    }
    while(q.top!=-1)
    {
        printf("%d",q.que[0]);
        pop();
    }
    return 0;
}
