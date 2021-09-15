#include<stdio.h>
#include<stdlib.h>

int n;

struct queue
{
int que[100];
int top1;
int top2;
}q;

void pushf(int item)
{
int i,temp=0;
q.top1++;
if(q.top1==q.top2)
    printf("queue full");
else
    q.que[q.top1] = item;
}

void popf()
{
int i;
for(i=0;i<q.top1;i++)
    q.que[i]=q.que[i+1];
q.top1--;
}

void pushb(int item)
{
int i,temp=0;
q.top2--;
if(q.top1==q.top2)
    printf("queue full");
else
    q.que[q.top2] = item;
}

void popb()
{
int i;
for(i=n;i>q.top2;i--)
    q.que[i]=q.que[i-1];
q.top2++;
}

int main()
{
    q.top1=-1;
    scanf("%d",&n);
    q.top2=n+1;
}
