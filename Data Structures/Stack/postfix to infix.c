#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

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

int isOperand(char ch)
{
	return(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isOperator(char x)
{
    switch (x)
    {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

int main()
{
	int i,k,l;
	char exp[100];
	scanf("%s", exp);
	//gets(exp);
	l=strlen(exp);
	strrev(exp);
    for (i=0,k=-1;exp[i];++i)
	{
		if (isOperator(exp[i]))
        {
            push(exp[i]);
        }
		else
		{
			exp[++k] = exp[i];
            exp[++k]=s.stk[s.top];
            pop();
		}
	}
	exp[++k] = '\0';
	strrev(exp);
	//puts(exp);
	return 0;
}
