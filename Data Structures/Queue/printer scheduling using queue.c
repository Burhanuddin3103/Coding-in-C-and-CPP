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
    int y;
    do
    {
    q.top=-1;
    int np,pjobs[100],i,j;
    float n,t=0,T[100];
    printf("\n\nenter the number of print jobs : ");
    scanf("%f",&n);
    printf("\nenter the number of pages for each job : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pjobs[i]);
        push(pjobs[i]);
    }
    printf("\nenter the number of printers : ");
    scanf("%d",&np);
    printf("the order in which the jobs were received : \n\n");
    for(i=0;i<n;i++)
        printf("%d ",pjobs[i]);
    printf("\n\nthe order in which the jobs were processed : \n\n");
    for(i=0;i<n;i++)
        printf("%.0f ",q.que[i]);
    switch(np)
    {
    case 1:
        {
            T[0]=0;
            for(i=0,j=1;i<n;i++,j++)
            {
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\njob\t\twaiting time\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-1]-1;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            break;
        }
    case 2:
        {
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
            printf("\n\njobs printed by printer 1 : ");
            for(i=0;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\njobs printed by printer 2 : ");
            for(i=1;i<n;i=i+2)
                printf("%.0f ",q.que[i]);
            printf("\n\njob\t\twaiting time\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-2]-2;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            break;
        }
    case 3:
        {
            T[0]=T[1]=T[2]=0;
            for(i=0,j=3;i<n;i++,j++)
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
                i++;
                j++;
                t=q.que[i]/10;
                if(t<1)
                    t=1;
                T[j]=t;
            }
            printf("\n\njobs printed by printer 1 : ");
            for(i=0;i<n;i=i+3)
                printf("%.0f ",q.que[i]);
                printf("\n\njobs printed by printer 2 : ");
            for(i=1;i<n;i=i+3)
                printf("%.0f ",q.que[i]);
                printf("\n\njobs printed by printer 3 : ");
            for(i=2;i<n;i=i+3)
                printf("%.0f ",q.que[i]);
            printf("\n\njob\t\twaiting time\n");
            for(i=0;i<n;i++)
            {
                T[i]=T[i]+T[i-3]-3;
                if(T[i]<0)
                    T[i]=0;
                printf("%.0f\t\t%.3f\n",q.que[i],T[i]);
            }
            break;
        }
    default:
        printf("invalid number of printers");
    }
    printf("\n\ndo you want to continue : 1.YES 2.NO\n");
    scanf("%d",&y);
    }while(y==1);
    return 0;
}
