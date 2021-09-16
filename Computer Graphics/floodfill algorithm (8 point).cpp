#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void FloodF(int p,int q,int newcolour,int oldcolour)
{
    int current;
    current = getpixel(p,q);
    if(current == oldcolour)
    {
        putpixel(p,q,newcolour);
        FloodF(p+1,q,newcolour,oldcolour);
        FloodF(p-1,q,newcolour,oldcolour);
        FloodF(p,q+1,newcolour,oldcolour);
        FloodF(p,q-1,newcolour,oldcolour);
        FloodF(p+1,q+1,newcolour,oldcolour);
        FloodF(p-1,q+1,newcolour,oldcolour);
        FloodF(p+1,q-1,newcolour,oldcolour);
        FloodF(p-1,q-1,newcolour,oldcolour);
    }
}

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");


    int x[20],y[20],X,Y,dx,dy,s,n,j,k,a=0,i=0;

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
        putpixel(X,Y,WHITE);
        while(k<=s)
        {
            X = X + dx;
            Y = Y + dy;
            k = k+1;
            putpixel(X,Y,WHITE);
        }
        if(a == 1)
        {
            break;
        }
    }


    int p,q,oldcolour,newcolour;
    oldcolour = BLACK;
    newcolour = RED;
    p = 51;
    q = 51;
    FloodF(p,q,newcolour,oldcolour);
    getch();
    closegraph();
    return 0;
}
