#include <stdio.h>

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
    int i,n,k,sum=0;
    printf("\n\nenter the number of people : ");
    scanf("%d",&n);
    printf("\n\nenter the number of people to skip : ");
    scanf("%d",&k);
    for (i =1;i<=n;i++)
        sum=(sum+k)%i;
    push(sum+1);
    printf("\n\nThe chosen place is %d",q.que[q.top]);
    return 0;
}
