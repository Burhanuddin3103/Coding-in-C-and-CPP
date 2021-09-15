#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stac
{
char* stk;
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
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	    return 1;
	case '-':
		return 1;
	case '*':
	    return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}

int main()
{
	char exp[100];
	gets(exp);
	s.stk=(char*) malloc(sizeof(exp));
	int i, k;
	for (i = 0,k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else if (exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == ')')
		{
			while (s.top!=0 && s.stk[s.top]!= '(')
            {
				exp[++k] =s.stk[s.top];
				pop();
            }
			if (s.top!=0 && s.stk[s.top]!= '(')
				return -1;
			else
				pop();
		}
		else
		{
			while (s.top!=0 && Prec(exp[i])<=Prec(s.stk[s.top]))
            {
				exp[++k] =s.stk[s.top];
				pop();
            }
			push(exp[i]);
		}
	}
	while (s.top!=0)
    {
        exp[++k] =s.stk[s.top];
        pop();
    }
	exp[++k] = '\0';
	printf( "%s", exp);
	return 0;
}
