#include <stdio.h>

int N, M;

struct queue
{
int que[100];
int top;
}q;

void push(int item)
{
int i,temp=0;
q.top++;
q.que[q.top] = item;
}

void pop()
{
int i;
for(i=0;i<q.top;i++)
    q.que[i]=q.que[i+1];
q.top--;
}

void createAdjMatrix(int Adj[][N + 1],int arr[][2])
{
	int i,j;
	for(i = 0; i < N; i++)
    {
		for(j = 0; j < N; j++)
		{
			Adj[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++)
    {
		int x = arr[i][0];
		int y = arr[i][1];
		Adj[x][y] = 1;
		Adj[y][x] = 1;
	}
}

void printAdjMatrix(int Adj[][N + 1])
{
	int i,j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
        {
			printf("%d ", Adj[i][j]);
		}
		printf("\n");
	}
}

void dsf(int Adj[][N+1])
{
    push(0);
    printf("\n");
    int i,j,k,l;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(Adj[i][j] == 1)
            {
                push(j);
                Adj[i][j] = 0;
                Adj[j][i] = 0;
                k = i;
                l = j;
                k++;
                while(k<N)
                {
                    if(Adj[k][l] == 1)
                    {
                        push(k);
                        Adj[k][l] = 0;
                        Adj[l][k] = 0;
                    }
                    k++;
                }
            }
        }
    }
    while(q.top>=0)
    {
        printf("%d",q.que[0]);
        pop();
    }
}

void bsf(int Adj[][N+1])
{
    push(0);
    printf("\n");
    int i,j,k,l;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(Adj[i][j] == 1)
            {
                push(j);
                Adj[i][j] = 0;
                Adj[j][i] = 0;
                k = i;
                while(k < N)
                {
                    Adj[k][j] = 0;
                    k++;
                }
            }
        }
    }
    while(q.top>=0)
    {
        printf("%d",q.que[0]);
        pop();
    }
}

int main()
{
	q.top = -1;
	int arr[100][2],i=0;
	printf("Enter the Number of Nodes : ");
	scanf("%d",&N);
	int Adj[N + 1][N + 1];
	printf("Enter the Number of Edges : ");
	scanf("%d",&M);
	printf("Enter source and Destination of each edge : ");
	for(i=0;i<M;i++)
    {
        printf("\nEdge %d : \n",i);
        scanf("%d",&arr[i][0]);
        scanf("%d",&arr[i][1]);
    }
	createAdjMatrix(Adj, arr);
	printf("The Adjecency Matrix of given Graph is : \n");
	printAdjMatrix(Adj);
	printf("\nThe DSF Traversal of Graph is : ");
	dsf(Adj);
	createAdjMatrix(Adj, arr);
	printf("\nThe BSF Traversal of Graph is : ");
	bsf(Adj);
	return 0;
}
