#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define MAX 100

struct stac
{
char stk[100];
int top;
}s;

void push(char item)
{
s.top++;
s.stk[s.top] = item;
}

void pop()
{
s.top--;
}

void main()
{
     int num;
     printf("Enter decimal number : ");
     scanf("%d",&num);
     while((num!=0))
     {
          push(num%2);
          num=num/2;
     }
    printf("\nthe binary conversion is : ");
    while(s.top!=0)
       {
       num=s.stk[s.top];
       pop();
       printf("%d",num);
       }
}
