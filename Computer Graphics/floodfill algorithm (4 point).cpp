#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

int x[20],y[20],n;

void floodfill(int x,int y,int newcolour,int oldcolour)
{
    int current;
    current = getpixel(x,y);
    if(current == oldcolour)
    {
        putpixel(x,y,newcolour);
        floodfill(x+1,y,newcolour,oldcolour);
        floodfill(x-1,y,newcolour,oldcolour);
        floodfill(x,y+1,newcolour,oldcolour);
        floodfill(x,y-1,newcolour,oldcolour);
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


    int oldcolour,newcolour,i;
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
    oldcolour = BLACK;
    newcolour = RED;
    fx = ((x[0]+x[1])/2 + x[2])/2;
    fy = ((y[0]+y[1])/2 + y[2])/2;
    floodfill(fx,fy,newcolour,oldcolour);
    getch();
    closegraph();
    return 0;
}
