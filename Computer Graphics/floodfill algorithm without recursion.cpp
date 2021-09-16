#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

int x[20],y[20],n;
int oldcolour = BLACK;
int newcolour = RED;

struct stac
{
    int x[10000];
    int y[10000];
    int counter[10000] = {0};
    int top;
}s;

void push(int x,int y)
{
    s.top++;
    s.x[s.top] = x;
    s.y[s.top] = y;
}

void pop()
{
    s.top--;
}

void floodfill(int x,int y)
{
    int current,xt,yt;
    xt = x;
    yt = y;
    s.top = 0;
    putpixel(xt,yt,newcolour);
    push(xt,yt);
    xt = xt + 1;
    while(s.top != 0)
    {
        current = getpixel(xt,yt);
        if(current == oldcolour)
        {
            putpixel(xt,yt,newcolour);
            push(xt,yt);
            xt = xt + 1;
        }
        else if(s.counter[s.top] == 0)
        {
            xt = s.x[s.top] - 1;
            s.counter[s.top]++;
        }
        else if(s.counter[s.top] == 1)
        {
            xt = s.x[s.top];
            yt = s.y[s.top] + 1;
            s.counter[s.top]++;
        }
        else if(s.counter[s.top] == 2)
        {
            xt = s.x[s.top];
            yt = s.y[s.top] - 1;
            s.counter[s.top]++;
        }
        else
            pop();
    }
}

void dda()
{
    int X,Y,dx,dy,s,j,k,a=0,i=0;
    for(i=0,j=1;i<n;i++,j++)
    {
        if(j == n)
        {
            j = j-1;
            i = 0;
            a = 1;
        }
        X = x[j]-x[i];
        if(X<0)
        {
            X = X * -1;
        }
        Y = y[j]-y[i];
        if(Y<0)
        {
            Y = Y * -1;
        }
        if(X>Y)
        {
            s = X;
        }
        else
        {
            s = Y;
        }
        dx = (x[j]-x[i])/s;
        dy = (y[j]-y[i])/s;
        X = x[i];
        Y = y[i];
        k = 1;
        putpixel(X,Y,YELLOW);
        while(k<=s)
        {
            X = X + dx;
            Y = Y + dy;
            k = k+1;
            putpixel(X,Y,YELLOW);
        }
        if(a == 1)
        {
            break;
        }
    }
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");

    int i;
    float fx,fy;

    printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("Enter the Co ordinates of points : ");
    for(i=0;i<n;i++)
    {
        printf("\npoint %d :\nx : ",i+1);
        scanf("%d",&x[i]);
        printf("\ny : ");
        scanf("%d",&y[i]);
    }
    dda();
    fx = ((x[0]+x[1])/2 + x[2])/2;
    fy = ((y[0]+y[1])/2 + y[2])/2;
    floodfill(fx,fy);
    getch();
    closegraph();
    return 0;
}
