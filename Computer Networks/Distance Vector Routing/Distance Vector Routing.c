#include <stdio.h>
#include <stdlib.h>

int main()
{
    int costmat[20][20],a[20][20],route[20][20];
    int nodes,i,j,k;
    printf("\nEnter Number of Nodes : ");
    scanf("%d",&nodes);
    printf("\nEnter the Cost Matrix Values : \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            a[i][j]=costmat[i][j];
        }
    }
    printf("\nCost Matrix : \n");
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            if( a[i][j] > 0)
            {
                for(k=0;k<nodes;k++)
                {
                    if( a[i][j] > costmat[i][k] + a[k][j])
                    {
                        a[i][j] = costmat[i][k] + a[k][j] ;
                        route[i][j] = k;
                    }
                }
            }
        }
    }
    for(i=0;i<nodes;i++)
    {
        printf("\n\n For router %d\n",i+1);
        for(j=0;j<nodes;j++)
        {
            printf("\t\nnode %d via %d Distance %d ",j+1,j+1,a[i][j]);
        }
    }
    printf("\n\n");
    return 0;
}
