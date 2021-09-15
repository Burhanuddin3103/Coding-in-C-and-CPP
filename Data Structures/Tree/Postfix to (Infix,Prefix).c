#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

int counter = 0;

typedef struct node n;
struct node
{
   char data;
   struct node *left;
   struct node *right;
};

n *root = NULL;

typedef struct stack s;
struct stack
{
   struct node* stk;
   struct stack *next;
};

s *head = NULL;


void Push(n* data)
{
    s *NewNode = (s*) malloc(sizeof(s));
    NewNode->stk = data;
    s *temp = head;
    if(head==NULL)
    {
        NewNode->next = head;
        head = NewNode;
    }
    else
    {
        while(temp->next != NULL)
            temp=temp->next;//while loop goes to last element of list
        temp->next=NewNode;//last element now points to new node
        NewNode->next = NULL;//end pointer from new node as it is being added in the end
    }
}

n* Pop()
{
    if(head==NULL)
        printf("list is empty");
    else
    {
        n *copy;
        s *temp = head;//copy head in temp
        s *second = head;
        if(temp->next != NULL)
        {
            temp = temp->next;
            while(temp->next != NULL)
            {
                second = temp;
                temp = temp->next;
            }
            copy = temp->stk;
            free(temp);//free first element stored in temp
            second->next = NULL;
            return copy;
        }
        else
        {
            copy = temp->stk;
            return copy;
        }
    }
}

void insertnode(char data,char parent,int position)
{
    int c = 0;
    c = counter;
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    n *temp = root;
    if(root == NULL)
    {
        root = NewNode;
    }
    else
    {
        do
        {
            while(temp->left != NULL)
            {
                if(temp->data != parent)
                {
                    Push(temp);
                    temp = temp->left;
                    c--;
                }
                else
                {
                    if(position == 1 && temp->left == NULL)
                    {
                        if(temp->left == NULL)
                        {
                            temp->left = NewNode;
                        }
                        else
                        {
                            printf("Position already Occupied.\n\n");
                        }
                    }
                    if(position == 2)
                    {
                        if(temp->right == NULL)
                        {
                            temp->right = NewNode;
                        }
                        else
                        {
                            printf("Position already Occupied.\n\n");
                        }
                    }
                    goto jump;
                }
            }
            if(temp->data == parent)
            {
                if(position == 1 && temp->left == NULL)
                {
                    if(temp->left == NULL)
                    {
                        temp->left = NewNode;
                    }
                    else
                    {
                        printf("Position already Occupied.\n\n");
                    }
                }
                if(position == 2)
                {
                    if(temp->right == NULL)
                    {
                        temp->right = NewNode;
                    }
                    else
                    {
                        printf("Position already Occupied.\n\n");
                    }
                }
                goto jump;
            }
            if(temp->right != NULL)
            {
                temp = temp->right;
                c--;
            }
            else
            {
                while(c != 0)
                {
                    temp = Pop();
                    if(temp->right != NULL)
                    {
                        temp = temp->right;
                        c--;
                        break;
                    }
                }
            }
        } while(c != 0);
        jump:;
    }
    counter++;
}

void postorder()
{
    n *temp = root;
    int c = 0 , d = 0;
    c = counter;
    if(c == 0)
    {
        printf("Tree Empty!");
        return;
    }
    printf("\n\n");
    do
    {
        while(temp->left != NULL)
        {
            Push(temp);
            temp = temp->left;
        }
        if(temp->right != NULL)
        {
            Push(temp);
            temp = temp->right;
        }
        else
        {
            printf("%c",temp->data);
            d = temp->data;
            c--;
            while(c != 0)
            {
                temp = Pop();
                if(c == 1)
                {
                    printf("%c",temp->data);
                    c--;
                    break;
                }
                if(temp->right != NULL && temp->right->data != d)
                {
                    Push(temp);
                    temp = temp->right;
                    break;
                }
                else
                {
                    printf("%c",temp->data);
                    d = temp->data;
                    c--;
                }
            }
        }
    } while(c != 0);
}

void preorder()
{
    n *temp = root;
    int c = 0;
    c = counter;
    if(c == 0)
    {
        printf("Tree Empty!");
        return;
    }
    printf("\n\n");
    do
    {
        while(temp->left != NULL)
        {
            Push(temp);
            printf("%c",temp->data);
            c--;
            temp = temp->left;
        }
        printf("%c",temp->data);
        c--;
        if(temp->right != NULL)
            temp = temp->right;
        else
        {
            while(c != 0)
            {
                temp = Pop();
                if(temp->right != NULL)
                {
                    temp = temp->right;
                    break;
                }
            }
        }
    } while(c != 0);
}

struct stac
{
char stk[100];
int top;
}s2;

void push(char item)
{
s2.top++;
s2.stk[s2.top] = item;
}

void pop()
{
s2.top--;
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

void intopre(char *exp)
{
	s2.top = -1;
	int l = strlen(exp);
	strrev(exp);
	int i, k;
	for (i = 0,k = -1; i<l; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];
		else
		{
			while (s2.top != 0 && Prec(exp[i])<=Prec(s2.stk[s2.top]))
            {
				exp[++k] =s2.stk[s2.top];
				pop();
            }
			push(exp[i]);
		}
	}
	while (s2.top != -1)
    {
        exp[++k] =s2.stk[s2.top];
        pop();
    }
	exp[++k] = '\0';
	strrev(exp);
}

void printlist()
{
    n* temp = root;
    while(temp->left != NULL)
    {
        printf(" %c ",temp->data);
        temp = temp->left;
    }
    printf(" %c ",temp->data);
    temp = root;
    while(temp->right != NULL)
    {
        printf(" %c ",temp->data);
        temp = temp->right;
    }
    printf(" %c ",temp->data);
}

int main()
{
    s2.top = -1;
    char exp[100];
    int l,i=0,p1=0,p2=0;
    printf("enter the infix expression : ");
    gets(exp);
    l=strlen(exp);
    intopre(exp);
        insertnode(exp[0],0,0);
    push(exp[0]);
    for(i=1;i<l;i++)
    {
        if(isOperator(exp[i]))
        {
            if(p1 == 0)
            {
                insertnode(exp[i],s2.stk[0],1);
                p1++;
            }
            else if(p1 == 1)
            {
                insertnode(exp[i],s2.stk[s2.top],2);
                p2--;
                pop();
            }
            push(exp[i]);
        }
        else
        {
            if(p2 == 0)
            {
                insertnode(exp[i],s2.stk[s2.top],1);
                p2++;
            }
            else
            {
                insertnode(exp[i],s2.stk[s2.top],2);
                //p1--;
                pop();
            }
        }
    }
    //printlist();
    printf("\nthe prefix expression is : ");
    preorder();
    printf("\nthe postfix expression is : ");
    postorder();
    return 0;
}
