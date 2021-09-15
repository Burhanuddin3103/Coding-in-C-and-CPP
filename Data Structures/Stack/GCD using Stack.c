#include <stdio.h>

struct stac
{
int stk[100];
int top;
}s;

void push(int item)
{
s.top++;
s.stk[s.top] = item;
}

void pop()
{
s.top--;
}

int gcd(int a,int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    if (a == b)
        return a;
    if (a > b)
    {
        push(a-b);
        return gcd(s.stk[s.top], b);
    }
    push(b-a);
    return gcd(a,s.stk[s.top]);
}

int main()
{
    int a,b;
    printf("enter the first number : ");
    scanf("%d",&a);
    printf("enter the second number : ");
    scanf("%d",&b);
    printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
    return 0;
}
