#include <stdio.h>
#include <conio.h>
#include <graphics.h>

main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    int n,i,j,k,dy,dx,x,y,temp,a[20][2],xi[20],ymax;
    float slope[20];

    printf("Enter the Number of Vertices : ");
    scanf("%d",&n);
    printf("Enter the Co ordinates of points : ");
    for(i=0;i<n;i++)
    {
        printf("\npoint %d :\nx : ",i+1);
        scanf("%d",&a[i][0]);
        printf("\ny : ");
        scanf("%d",&a[i][1]);
    }
    a[n][0]=a[0][0];
    a[n][1]=a[0][1];
    for(i=0;i<n;i++)
    {
        line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
    }
    for(i=0;i<n;i++)
    {
        dy=a[i+1][1]-a[i][1];
        dx=a[i+1][0]-a[i][0];
        if(dy==0)
            slope[i]=1.0;
        if(dx==0)
            slope[i]=0.0;
        if((dy!=0)&&(dx!=0))
        {
            slope[i]=(float) dx/dy;
        }
    }
    ymax = a[0][1];
    for(i=0;i<n;i++)
        if(a[i][1]>ymax)
            ymax = a[i][0];
    for(y=0;y<ymax-1;y++)
    {
        k=0;
        for(i=0;i<n;i++)
        {
            if(((a[i][1]<=y)&&(a[i+1][1]>y))||((a[i][1]>y)&&(a[i+1][1]<=y)))
            {
                xi[k]=(int)(a[i][0]+slope[i]*(y-a[i][1]));
                k++;
            }
        }
        for(j=0;j<k-1;j++)
        {
            for(i=0;i<k-1;i++)
            {
                if(xi[i]>xi[i+1])
                {
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }
        }

        setcolor(RED);
        for(i=0;i<k;i+=2)
        {
            line(xi[i],y+1,xi[i+1],y+1);
            delay(1);
        }
    }
    getch();
    closegraph();
}
