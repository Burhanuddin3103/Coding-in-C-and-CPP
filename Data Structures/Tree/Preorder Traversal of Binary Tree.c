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

void insertnode(int data)
{
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
        if(temp->left != NULL || temp->right != NULL)
        {
            jump2: while(temp->data >= NewNode->data && temp->left != NULL)
            {
                temp = temp->left;
                if(temp->left == NULL)
                    goto jump;
            }
            while(temp->data <= NewNode->data && temp->right != NULL)
            {
                temp = temp->right;
                if(temp->left != NULL && temp->data >= NewNode->data)
                    goto jump2;
                if(temp->right == NULL)
                    goto jump;
            }
        }
        jump: if(temp->data >= NewNode->data)
        {
            temp->left = NewNode;
        }
        else
        {
            temp->right = NewNode;
        }
    }
    counter++;
}

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
            printf(" %d ",temp->data);
            c--;
            temp = temp->left;
        }
        printf(" %d ",temp->data);
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

void printlist()
{
    n* temp = root;
    while(temp->left != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->left;
    }
    printf(" %d ",temp->data);
    temp = root;
    while(temp->right != NULL)
    {
        printf(" %d ",temp->data);
        temp = temp->right;
    }
    printf(" %d ",temp->data);
}

int main()
{
    int x=0;
    do
    {
        printf("\n1. Add Node\n2. Delete Node\n3. Print Inorder Sequence of Given Tree\n4. Print Inorder Sequence of Mirror Image of Given Tree\n5. Exit\n\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            {
                int n = 0;
                printf("\n\nEnter The Number to be Added : ");
                scanf("%d",&n);
                insertnode(n);
                break;
            }
        case 2:
            {
                printf("\n\nThe Given Tree is : ");
                preorder();
                break;
            }
        /*case 4:
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
