#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bal=0;
int counter = 0;

typedef struct node n;
struct node
{
 char *data;
 struct node *left;
 struct node *right;
 struct node *up;
};

n *root=NULL;

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

int getHeight(n *p)
{
 int i,j;
 if(!p)
  return 0;
 else
 {
  i=getHeight(p->left);
  j=getHeight(p->right);
  if(i>j)
   return i+1;
  else
   return j+1;
 }
}

int getBalance(n *p)
{
 return getHeight(p->left)-getHeight(p->right);
}

n* getNode(n *p)
{
    while(p)
    {
        bal=getBalance(p);
        printf("\n\tBalance factor of %s node is %d",&p->data,bal);
        if(bal>1||bal<-1)
            return p;
        else
            p=p->up;
    }
    return p;
}

void rightRotate(n *y)
{
    n *x = y->left,*Temp;

    Temp = x->right;
 if(y==root)
  root=x;
    else
    {
  if(y->up->left==y)
   y->up->left=x;
  else
   y->up->right=x;
 }

    // Perform rotation
    x->up = y->up;
    y->up = x;
    x->right = y;
    y->left = Temp;
    if(Temp!=NULL)
    Temp->up = x;
}

void leftRotate(n *x)
{
    n *y = x->right,*temp;

 temp = y->left;
    // Perform rotation
    if(x==root)
    {
  root=y;
 }else
 {
  if(x->up->left==x)
   x->up->left=y;
  else
   x->up->right=y;
 }
    y->up=x->up;
    x->up=y;
    y->left = x;
    x->right = temp;
    if(temp!=NULL)
     temp->up=x;
 else
  return;
}

void balace(n *p,char *data)
{
    if(bal>1 && data < p->left->data)
    {
        printf("\n\tRight rotation get performed on unbalanced node %s",p->data);
        rightRotate(p);
    }
    else
    {
        if(bal<-1 && data > p->right->data)
        {
            printf("\n\tLeft rotation get performed on unbalanced node %s",p->data);
            leftRotate(p);
        }
        else
        {
            if(bal>1 && data > p->left->data)
            {
                printf("\n\tLeft Right rotation get performed on unbalanced node %s",p->data);
                leftRotate(p->left);
                rightRotate(p);
            }
            else
            {
                if(bal<-1 && data < p->right->data)
                {
                    printf("\n\tRight Left rotation get performed on unbalanced node %s",p->data);
                    rightRotate(p->right);
                    leftRotate(p);
                }
            }
        }
    }
}

void insert(char *d)
{
    counter++;
    n *p=(n*)malloc(sizeof(n));
    p->data=d;
    p->left=NULL;
    p->right=NULL;
    p->up=NULL;
    n *q = root;
    n *r = root;
    n *s = root;
    if(root==NULL)
    {
        root=p;
        printf("\nRoot Node: %s is added",&d);
    }
    else
    {
        while(q)
        {
            r = q;
            if(d >= q->data)
                q = q->right;
            else
                q = q->left;
        }
        if(d >= r->data)
        {
            printf("\n\nNode: %s is added to right of %s",&d,&r->data);
            r->right=p;
            p->up=r;
        }
        else
        {
            printf("\n\nNode: %s is added to left of %s",&d,&r->data);
            r->left=p;
            p->up=r;
        }
    }
    s = getNode(p);
    if(s!=NULL)
        balace(s,d);
    else
        return;
}

void levelwise()
{
    n *temp = root;
    int c = 0 , i = 0,h = 1;
    c = counter;
    if(c == 0)
    {
        printf("Tree Empty!");
        return;
    }
    printf("\n\n");
    printf("\n\nLEVEL %d : ",h);
    printf(" %s ",&temp->data);
    c--;
    h++;
    do
    {
        temp = root;
        i=2;
        printf("\n\nLEVEL %d : ",h);
        while(i<h && c != 0)
        {
            if(temp->left != NULL)
                temp = temp->left;
            else if(temp->right != NULL)
                temp = temp->right;
            i++;
        }
        if(temp->left != NULL)
        {
            Push(temp);
            temp = temp->left;
        }
        printf(" %s ",&temp->data);
        c--;
        temp = Pop();
        if(temp->right != NULL)
        {
            temp = temp->right;
            printf(" %s ",&temp->data);
            c--;
        }
        if(h == 2)
            goto jump;
        temp = root;
        i = 2;
        while(i<h && c != 0)
        {
            if(temp->right != NULL)
                temp = temp->right;
            else if(temp->left != NULL)
                temp = temp->left;
            i++;
        }
        if(temp->left != NULL)
        {
            Push(temp);
            temp = temp->left;
        }
        else
            goto jump2;
        if(c != 0)
        {
            printf(" %s ",&temp->data);
            c--;
        }
        temp = Pop();
        jump2:
        if(temp->right != NULL)
        {
            temp = temp->right;
            printf(" %s ",&temp->data);
            c--;
        }
        jump:
        h++;
    }while(c > 0);
}

void printlist()
{
    n* temp = root;
    while(temp->left != NULL)
    {
        printf(" %s ",temp->data);
        temp = temp->left;
    }
    printf(" %s ",temp->data);
    temp = root;
    while(temp->right != NULL)
    {
        printf(" %s ",temp->data);
        temp = temp->right;
    }
    printf(" %s ",temp->data);
}

int main()
{
    int x=0;
    do
    {
        printf("\n\n\n1. Add Node\n2. Print Given Tree LevelWise\n3. Exit\n\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            {
                char *n;
                printf("\n\nEnter The Number to be Added : ");
                scanf("%s",&n);
                insert(n);
                break;
            }
        case 2:
            {
                printf("\n\nAVL Tree LevelWise : ");
                levelwise();
                break;
            }
        case 3:
            break;
        }
    }while(x != 3);
    //printlist();
    return 0;
}
