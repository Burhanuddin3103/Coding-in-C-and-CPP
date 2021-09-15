#include <stdio.h>
#include <stdlib.h>

int counter = 0;

typedef struct node n;
struct node
{
   int data;
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

void insertnode(int data,int parent,int position)
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
                            printf("Node Added Successfully.\n\n");
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
                            printf("Node Added Successfully.\n\n");
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
                        printf("Node Added Successfully.\n\n");
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
                        printf("Node Added Successfully.\n\n");
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
            printf(" %d ",temp->data);
            d = temp->data;
            c--;
            while(c != 0)
            {
                temp = Pop();
                if(c == 1)
                {
                    printf(" %d ",temp->data);
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
                    printf(" %d ",temp->data);
                    c--;
                }
            }
        }
    } while(c != 0);
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
    printf(" %d ",temp->data);
    c--;
    h++;
    while(c != 0)
    {
        temp = root;
        i=2;
        printf("\n\nLEVEL %d : ",h);
        while(i<h)
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
        printf(" %d ",temp->data);
        c--;
        temp = Pop();
        if(temp->right != NULL)
        {
            temp = temp->right;
            printf(" %d ",temp->data);
            c--;
        }
        if(h == 2)
            goto jump;
        temp = root;
        i = 2;
        while(i<h)
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
            printf(" %d ",temp->data);
            c--;
        }
        temp = Pop();
        jump2: if(temp->right != NULL)
        {
            temp = temp->right;
            printf(" %d ",temp->data);
            c--;
        }
        jump:h++;
    }
}

void leafnodes()
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
            temp = temp->left;
        }
        if(temp->right ==NULL)
        {
            printf(" %d ",temp->data);
            c--;
            goto jump;
        }
        if(temp->right != NULL)
            temp = temp->right;
        else
        {
            jump: while(c != 0)
            {
                temp = Pop();
                c--;
                if(temp->right != NULL)
                {
                    temp = temp->right;
                    break;
                }
            }
        }
    } while(c != 0);
}

void printlist()
{
    n* temp = root;
    printf(" %d ",temp->data);
    while(temp->right != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->right;
    }
    temp = root;
    while(temp->left != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->left;
    }
}

int main()
{
    int x=0;
    do
    {
        printf("\n1. Add Node\n2. Print Postorder Sequence of Given Tree\n3. Print Tree Level Wise\n4. Display Leaf Nodes\n5. Exit\n\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            {
                int n,p,pos;
                printf("\n\nEnter The Number to be Added : ");
                scanf("%d",&n);
                if(root != NULL)
                {
                    printf("\n\nEnter Parent Node : ");
                    scanf("%d",&p);
                    printf("\n\nEnter The Position :\n1. Left\n2. Right\n ");
                    scanf("%d",&pos);
                    insertnode(n,p,pos);
                }
                else
                {
                    insertnode(n,0,0);
                }
                break;
            }
        case 2:
            {
                printf("\n\nThe Given Tree is : ");
                postorder();
                break;
            }
        case 3:
            {
                printf("\n\nLevel Wise Tree : ");
                levelwise();
                break;
            }
        case 4:
            {
                printf("\n\nThe Leaf Nodes of Given Tree are : ");
                leafnodes();
                break;
            }
        /*case 6:
            {
                printlist();
                break;
            }*/
        case 5:
            break;
        }
    }while(x != 5);
    return 0;
}
