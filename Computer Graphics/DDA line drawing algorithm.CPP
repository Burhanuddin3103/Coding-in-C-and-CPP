#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

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
    getch();
    closegraph();
}
