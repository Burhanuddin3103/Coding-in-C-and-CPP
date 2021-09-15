#include<stdio.h>
#include<stdlib.h>

struct queue
{
float que[100];
int top;
}q;

void push(float item)
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
    int cust[100],i,j;
    float n,t=0,T[100];
    printf("this simulation assumes that a customer enters the bank every minute\n\n");
    printf("\n\nenter the number of customers at the bank : ");
    scanf("%f",&n);
    printf("\nenter the time required for each customer to finish his/her work(in minutes) : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&cust[i]);
        push(cust[i]);
    }
            printf("\n\nwaiting time for 1 teller : \n");
            T[0]=0;
            for(i=0,j=1;i<n;i++,j++)
            {
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\njob\t\twaiting time(in minutes)\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-1]-1;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            printf("\n\nwaiting time for 2 tellers : \n");
            T[0]=T[1]=0;
            for(i=0,j=2;i<n;i++,j++)
            {
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                    T[j]=t;
                i++;
                j++;
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\njobs completed by teller 1 : ");
            for(i=0;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\njobs completed by teller 2 : ");
            for(i=1;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\njob\t\twaiting time(in minutes)\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-2]-2;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
    return 0;
}
