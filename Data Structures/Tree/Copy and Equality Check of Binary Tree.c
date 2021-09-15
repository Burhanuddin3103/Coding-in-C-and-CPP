#include <stdio.h>
#include <stdlib.h>

int counter = 0;
int counter2 = 0;
int counter3 = 0;

typedef struct node n;
struct node
{
   int data;
   struct node *left;
   struct node *right;
};

n *root = NULL;
n *root2 = NULL;
n *root3 = NULL;

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

void insertnode(int data , int treeno)
{
    n *temp;
    if(treeno == 1)
        temp = root;
    else if (treeno == 2)
        temp = root2;
    else
        temp = root3;
    n *NewNode = (n*)malloc(sizeof(n));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    if(root == NULL && treeno == 1)
    {
        root = NewNode;
    }
    else if(root2 == NULL && treeno == 2)
    {
        root2 = NewNode;
    }
    else if(root3 == NULL && treeno == 3)
    {
        root3 = NewNode;
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
    if(treeno == 1)
        counter++;
    else if(treeno == 3)
        counter3++;
}

void inorder(int treeno)
{
    n *temp;
    if(treeno == 1)
        temp = root;
    else if(treeno == 2)
        temp = root2;
    else
        temp = root3;
    int c = 0;
    if(treeno == 1)
        c = counter;
    else if(treeno == 2)
        c = counter2;
    if(treeno == 3)
        c = counter3;
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

void copytree()
{
    root2 = NULL;
    int c = 0;
    c = counter;
    counter2 = counter;
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
            insertnode(temp->data,2);
            c--;
            Push(temp);
            temp = temp->left;
        }
        insertnode(temp->data,2);
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
                    insertnode(temp->data,2);
                    c--;
                    break;
                }
            }
        }
    }while(c != 0);
}

void deleteIterative(int data)
{
    counter--;
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
}

void equality()
{
    n *temp = root;
    n *temp2 = root3;
    int c1,c2,i=0,f1=0,f2=0,arr1[100],arr2[100];
    c1 = counter;
    c2 = counter3;
    if(c1 != c2)
    {
        printf("Trees are Unequal.");
        return;
    }
    do
    {
        while(temp->left != NULL)
        {
            Push(temp);
            arr1[i] = temp->data;
            i++;
            c1--;
            temp = temp->left;
        }
        arr1[i] = temp->data;
        i++;
        c1--;
        if(temp->right != NULL)
            temp = temp->right;
        else
        {
            while(c1 != 0)
            {
                temp = Pop();
                if(temp->right != NULL)
                {
                    temp = temp->right;
                    break;
                }
            }
        }
    } while(c1 != 0);
    i = 0;
    do
    {
        while(temp2->left != NULL)
        {
            Push(temp2);
            arr2[i] = temp2->data;
            i++;
            c2--;
            temp2 = temp2->left;
        }
        arr2[i] = temp2->data;
        i++;
        c2--;
        if(temp2->right != NULL)
            temp2 = temp2->right;
        else
        {
            while(c2 != 0)
            {
                temp2 = Pop();
                if(temp2->right != NULL)
                {
                    temp2 = temp2->right;
                    break;
                }
            }
        }
    } while(c2 != 0);
    c2 = counter3;
    i = 0;
    while(c2 != 0)
    {
        if(arr1[i] == arr2[i])
        {
            i++;
        }
        else
        {
            f1 = 1;
        }
        c2--;
    }
    temp = root;
    temp2 = root3;
    c1 = counter;
    c2 = counter3;
    i = 0;
    do
    {
        while(temp->left != NULL)
        {
            Push(temp);
            temp = temp->left;
        }
        arr1[i] = temp->data;
        i++;
        c1--;
        if(temp->right != NULL)
            temp = temp->right;
        else
        {
            while(c1 != 0)
            {
                temp = Pop();
                arr1[i] = temp->data;
                i++;
                c1--;
                if(temp->right != NULL)
                {
                    temp = temp->right;
                    break;
                }
            }
        }
    } while(c1 != 0);
    i = 0;
    do
    {
        while(temp2->left != NULL)
        {
            Push(temp2);
            temp2 = temp2->left;
        }
        arr2[i] = temp2->data;
        i++;
        c2--;
        if(temp2->right != NULL)
            temp2 = temp2->right;
        else
        {
            while(c2 != 0)
            {
                temp2 = Pop();
                arr2[i] = temp2->data;
                i++;
                c2--;
                if(temp2->right != NULL)
                {
                    temp2 = temp2->right;
                    break;
                }
            }
        }
    } while(c2 != 0);
    c2 = counter3;
    i = 0;
    while(c2 != 0)
    {
        if(arr1[i] == arr2[i])
        {
            i++;
        }
        else
        {
            f2 = 1;
        }
        c2--;
    }
    if(f1 == 0 && f2 == 0)
        printf("Trees are Equal.");
    else
        printf("Trees are Unequal.");
}

void printlist()
{
    /*n* temp = root2;
    while(temp != NULL)
    {
    printf(" %d ",temp->data);
    temp = temp->left;
    }*/
    //printf(" %d ",temp->data);
    //temp = root2;
    //temp = temp->left;
    printf(" %d ",counter);
}

int main()
{
    int x=0;
    do
    {
        printf("\n1. Add Node\n2. Delete Node\n3. Print Inorder Sequence of Given Tree\n");
        printf("4. Copy Tree\n5. Print Inorder Sequence of Copied of Given Tree\n6. Check for Equality\n7. Exit\n\n");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            {
                int n = 0;
                int t = 0;
                printf("\n\nEnter The Number to be Added : ");
                scanf("%d",&n);
                printf("\n\nEnter The Tree Number to which Node is to be Added : ");
                scanf("%d",&t);
                if(t == 1)
                    insertnode(n,1);
                else
                    insertnode(n,3);
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
                int t = 0;
                printf("Enter the Tree Number to be printed : ");
                scanf("%d",&t);
                printf("\n\nThe Given Tree is : ");
                if(t == 1)
                    inorder(1);
                else
                    inorder(3);
                break;
            }
        case 4:
            {
                copytree();
                printf("\n\nTree Copied.");
                break;
            }
        case 5:
            {
                printf("\n\nThe Copied Tree is : ");
                inorder(2);
                break;
            }
        case 8:
            {
                printlist();
                break;
            }
        case 6:
            {
                equality();
                break;
            }
        case 7:
            break;
        }
    }while(x != 7);
    return 0;
}
