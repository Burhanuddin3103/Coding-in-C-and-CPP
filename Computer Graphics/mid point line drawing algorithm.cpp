#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void drawcircle(int xc,int yc,int x,int y)
{
    putpixel(xc+x, yc+y, YELLOW);
    putpixel(xc-x, yc+y, YELLOW);
    putpixel(xc+x, yc-y, YELLOW);
    putpixel(xc-x, yc-y, YELLOW);
    putpixel(xc+y, yc+x, YELLOW);
    putpixel(xc-y, yc+x, YELLOW);
    putpixel(xc+y, yc-x, YELLOW);
    putpixel(xc-y, yc-x, YELLOW);
}

int main()
{
	int gd = DETECT,gm;
    initgraph(&gd,&gm,"");

    int X,Y,R,D,XC,YC;
    printf("MID POINT CIRCLE DRAWING ALGORITHM");
    printf("\nEnter the radius : ");
    scanf("%d",&R);
    printf("\n\nEnter the Co ordinates of center of Circle : ");
    printf("\nX : ");
    scanf("%d",&XC);
    printf("\nY : ");
    scanf("%d",&YC);
    X = R;
    Y = 0;
    D = 0;
	while (X >= Y)
    {
        drawcircle(XC,YC,X,Y);
        if (D <= 0)
        {
            Y = Y + 1;
            D = D + 2*Y + 1;
        }

        if (D > 0)
        {
            X = X - 1;
            D = D - 2*X + 1;
        }
    }
	getch();
	closegraph();
	return 0;
}
