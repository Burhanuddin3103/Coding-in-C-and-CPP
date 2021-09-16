#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int x[20],y[20],X,Y,dx,dy,s1,s2,n,p,v,temp,swap,j,k,a=0,i=0;

    printf("Enter the Number of Vertices : ");
    scanf("%d",&v);
    printf("Enter the Co ordinates of points : ");
    for(i=0;i<v;i++)
    {
        printf("\npoint %d :\nx : ",i+1);
        scanf("%d",&x[i]);
        printf("\ny : ");
        scanf("%d",&y[i]);
    }
    for(i=0,j=1;i<v;i++,j++)
    {
        if(j == v)
        {
            j = j-1;
            i = 0;
            a = 1;
        }
        X = x[i];
        Y = y[i];
        dx = x[j]-x[i];
        if(dx < 0)
        {
            dx = dx * -1;
        }
        dy = y[j]-y[i];
        if(dy < 0)
        {
            dy = dy * -1;
        }
        s1 = (x[j]-x[i])/dx;
        s2 = (y[j]-y[i])/dy;
        if(dy > dx)
        {
            temp = dx;
            dx = dy;
            dy = temp;
            swap = 1;
        }
        else
        {
            swap = 0;
        }
        n = 1;
        p = 2 * (dy - dx);
        putpixel(X,Y,RED);
        while(n<=dx)
        {
            if(p >= 0)
            {
                X = X + s1;
                Y = Y + s2;
                p = p + (2*(dy-dx));
            }
            else
            {
                if(swap == 1)
                {
                    Y = Y + s2;
                }
                else
                {
                    X = X + s1;
                }
                p = p + 2*dy;
            }
            n = n + 1;
            putpixel(X,Y,RED);
        }
        if(a == 1)
        {
            break;
        }
    }
    getch();
    closegraph();
    return 0;
}
