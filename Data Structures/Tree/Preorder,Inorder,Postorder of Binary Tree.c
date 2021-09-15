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
    n *temp2 = root;
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
                //temp = temp->left;
                if(temp->left == temp2)
                    goto jump;
                else
                {
                    temp = temp->left;
                    temp2 = temp->right;
                }
                if(temp->left == NULL)
                    goto jump;
            }
            while(temp->data <= NewNode->data && temp->right != NULL)
            {
                if(temp->right == temp2)
                    goto jump;
                else
                {
                    temp = temp->right;
                    temp2 = temp->left;
                }
                if(temp->left != NULL && temp->data >= NewNode->data)
                    goto jump2;
                if(temp->right == NULL)
                    goto jump;
            }
        }
        jump: if(temp->data >= NewNode->data)
        {
            if(temp->left != NULL)
                NewNode->left = temp->left;
            temp->left = NewNode;
            NewNode->right = temp;
        }
        else
        {
            if(temp->right != NULL)
                NewNode->right = temp->right;
            temp->right = NewNode;
            NewNode->left = temp;
        }
    }
    counter++;
}

void inorder()
{
    n *temp = root;
    n *temp2 = root;
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
            if(temp->left != temp2)
                temp = temp->left;
            else
                break;
        }
        printf(" %d ",temp->data);
        c--;
        while(temp->right != NULL && c != 0)
        {
            temp2 = temp;
            temp = temp->right;
            if(temp->left != temp2 && temp != root)
            {
                temp2 = root;
                break;
            }
            printf(" %d ",temp->data);
            c--;
        }
    } while(c != 0);
}

void preorder()
{
    n *temp = root;
    n *temp2 = root;
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
            if(temp->left != root)
            {
                temp2 = temp;
                printf(" %d ",temp->data);
                c--;
                temp = temp->left;
            }
            else
                break;
        }
        printf(" %d ",temp->data);
        c--;
        if(temp == temp2)
        {
            temp2 = temp2->right;
            printf(" %d ",temp2->data);
            c--;
        }
        while(temp->right != NULL && c != 0)
        {
            temp = temp->right;
            temp2 = temp2->right;
            if(temp->right == NULL)
            {
                printf(" %d ",temp->data);
                c--;
                break;
            }
            if(temp2->right == NULL)
            {
                printf(" %d ",temp2->data);
                c--;
                break;
            }
            if(temp2->left != temp && temp2 != root)
            {
                temp = temp2;
                temp2 = root;
                break;
            }
            if(temp2 != root)
            {
                printf(" %d ",temp2->data);
                c--;
            }
        }
    } while(c != 0);
}

void postorder()
{
    n *temp = root;
    n *temp2 = root;
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
            if(temp->left != temp2 && temp->left != root)
            {
                temp2 = temp;
                temp = temp->left;
            }
            else
                break;
        }
        if(temp->right == temp2)
        {
            printf(" %d ",temp->data);
            c--;
        }
        else
            temp2 = temp2->right;
        if(temp == temp2)
            temp2 = temp2->right;
        while(temp->right != NULL && c != 0)
        {
            if(temp2->right != NULL)
            {
                temp = temp->right;
                temp2 = temp2->right;
            }
            else
            {
                while(c != 1)
                {
                    printf(" %d ",temp2->data);
                    c--;
                    temp2 = temp2->left;
                }
                break;
            }
            if(temp2->left != temp && temp2 != root)
            {
                temp = temp2;
                temp2 = root;
                break;
            }
            else if(temp2->right == root)
            {
                printf(" %d ",temp2->data);
                c--;
                printf(" %d ",temp->data);
                c--;
            }
        }
        if(c == 1)
        {
            temp = root;
            printf(" %d ",temp->data);
            c--;
        }
    } while(c != 0);
}

void printlist()
{
    n *temp = root;
    printf(" %d ",temp->data);
    temp = temp->right;
    printf(" %d ",temp->data);
    temp = temp->left;
    printf(" %d ",temp->data);

    /*while(temp->right != NULL)
    {
        temp = temp->right;
        printf(" %d ",temp->data);
    }
    //temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
        printf(" %d ",temp->data);
    }
    while(temp->right != NULL)
    {
        temp = temp->right;
        printf(" %d ",temp->data);
    }*/
}

int main()
{
    int x=0;
    do
    {
        printf("\n1. Add Node\n2. Print Inorder Sequence of Given Tree\n3. Print Preorder Sequence of Given Tree\n");
        printf("4. Print Postorder Sequence of Given Tree\n5. Exit\n\n");
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
                inorder();
                break;
            }
        case 3:
            {
                printf("\n\nThe Given Tree is : ");
                preorder();
                break;
            }
        case 4:
            {
                printf("\n\nThe Given Tree is : ");
                postorder();
                break;
            }
        case 6:
            {
                printlist();
                break;
            }
        case 5:
            break;
        }
    }while(x != 5);
    return 0;
}
