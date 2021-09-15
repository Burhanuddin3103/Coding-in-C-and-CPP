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
n *root2 = NULL;

void mirror(int data)
{
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    n *temp = root2;
    if(root2 == NULL)
    {
        root2 = NewNode;
    }
    else
    {
        if(temp->left != NULL || temp->right != NULL)
        {
            jump2: while(temp->data >= NewNode->data && temp->right != NULL)
            {
                temp = temp->right;
                if(temp->right == NULL)
                    goto jump;
            }
            while(temp->data <= NewNode->data && temp->left != NULL)
            {
                temp = temp->left;
                if(temp->right != NULL && temp->data >= NewNode->data)
                    goto jump2;
                if(temp->left == NULL)
                    goto jump;
            }
        }
        jump: if(temp->data >= NewNode->data)
        {
            temp->right = NewNode;
        }
        else
        {
            temp->left = NewNode;
        }
    }
}

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

void mirrortree()
{
    root2 = NULL;
    int c = 0;
    c = counter;
    n *temp = root;
    if(c == 0)
    {
        printf("Tree Empty!");
        return;
    }
    do
    {
        while(temp->left != NULL)
        {
            mirror(temp->data);
            c--;
            Push(temp);
            temp = temp->left;
        }
        mirror(temp->data);
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
    }while(c != 0);
}

void inorder(int treeno)
{
    n *temp;
    if(treeno == 1)
        temp = root;
    if(treeno == 2)
        temp = root2;
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
        printf(" %d ",temp->data);
        c--;
        if(temp->right != NULL)
            temp = temp->right;
        else
        {
            while(c != 0)
            {
                temp = Pop();
                printf(" %d ",temp->data);
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

void deleteIterative(int data)
{
    n* curr = root;
    n* prev = root;
    while (curr != NULL && curr->data != data)
    {
        prev = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr == NULL)
    {
        printf("Data %d not found in the provided Tree.\n",data);
        return;
    }
    if (curr->left == NULL || curr->right == NULL)
    {
        n* newCurr;
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
        free(curr);
    }
    else
    {
        n* second = NULL;
        n* temp = root;
        temp = curr->right;
        while (temp->left != NULL)
        {
            second = temp;
            temp = temp->left;
        }
        if (second != NULL)
            second->left = temp->right;
        else
            curr->right = temp->right;
        curr->data = temp->data;
        free(temp);
    }
    counter--;
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
                int n = 0;
                printf("\n\nEnter The Number to be Deleted: ");
                scanf("%d",&n);
                deleteIterative(n);
                break;
            }
        case 3:
            {
                printf("\n\nThe Given Tree is : ");
                inorder(1);
                break;
            }
        case 4:
            {
                printf("\n\nThe Mirror of Given Tree is : ");
                mirrortree();
                inorder(2);
                break;
            }
        /*case 5:
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
