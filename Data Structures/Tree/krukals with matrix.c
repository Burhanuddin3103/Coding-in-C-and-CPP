#include<stdio.h>
#include<stdlib.h>
#define MAX 999;

int vertices,edges,arr[100][2];

typedef struct node k;
struct node
{
    int v1;
    int v2;
    int weight;
}G[20];

int find (int v2,int parent[])
{
    while(parent[v2]!=v2)
    {
        v2=parent[v2];
    }
}

void uni(int i,int j,int parent[])
{
    if(i<j)
        parent[j]=i;
    else
        parent[i]=j;
}

void create()
{
    printf("\n enter edges in v1-v2 form and corresponding weight : ");
    for(int k=0;k<edges;k++)
    {
      printf("\nv1 : ");
      scanf("%d",&G[k].v1);
      arr[k][0] = G[k].v1;
      printf("\nv2 : ");
      scanf("%d",&G[k].v2);
      arr[k][1] = G[k].v2;
      printf("\nweight : ");
      scanf("%d",&G[k].weight);
    }
}

int minimum(int n)
{
    int i,small,pos;
    small=MAX;
    pos=-1;
    for(i=0;i<n;i++)
    {
        if(G[i].weight<small)
        {
            small=G[i].weight;
            pos=i;
        }
    }
    return pos;
}

void minweight()
{
    int count,k,v1,v2,i,j,tree[10][10],pos,parent[10];
    int sum=0;
    count=0;
    k=0;
    for(i=0;i<vertices;i++)
        parent[i]=i;
    while(count!=vertices-1)
    {
    pos=minimum(edges);
    if(pos==-1)
        break;
    v1=G[pos].v1;
    v2=G[pos].v2;
    i=find(v1,parent);
    j=find(v2,parent);
    if(i!=j)
        {
        tree[k][0]=v1;
        tree[k][1]=v2;
        k++;
        count++;
        sum=sum+G[pos].weight;
        uni(i,j,parent);
        }
    G[pos].weight=MAX;
    }
    if(count==vertices-1)
    {
        printf("The minimum spanning tree is : ");
        for(i=0;i<vertices-1;i++)
        {
            printf(" %d - %d ",tree[i][0],tree[i][1]);
        }
    }
}

void createAdjMatrix(int Adj[][vertices + 1])
{
	int i,j;
	for(i = 0; i < vertices; i++)
    {
		for(j = 0; j < vertices; j++)
		{
			Adj[i][j] = 0;
		}
	}
	for (int i = 0; i < edges; i++)
    {
		int x = arr[i][0];
		int y = arr[i][1];
		Adj[x][y] = G[i].weight;
		Adj[y][x] = G[i].weight;
	}
}

void printAdjMatrix(int Adj[][vertices + 1])
{
	int i,j;
	printf("\n\n");
	for(i = 0; i < vertices; i++)
	{
		for(j = 0; j < vertices; j++)
        {
			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}
}

int main()
{
    printf("enter number of vertices : ");
    scanf("%d",&vertices);
    printf("enter number of edges : ");
    scanf("%d",&edges);
    int Adj[vertices + 1][vertices + 1];
    create();
    createAdjMatrix(Adj);
    printAdjMatrix(Adj);
    minweight();
    return 0;
}
