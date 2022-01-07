#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;

int XC=50,YC=175,XE=600,YE=415,R=10;

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

void midpoint(int m,int n)
{
    int X,Y,D;
    X = R;
    Y = 0;
    D = 0;
	while (X >= Y)
    {
        drawcircle(m,n,X,Y);
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

}

void newcoordinate(int s[][3], int p[][1])
{
	int temp[3][1] = { 0 };
    int i,j,k;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
	p[2][0] = temp[2][0];
}

void translate(int tx,int ty)
{
	int s[3][3] = {1,0,tx,0,1,ty,0,0,1};
	int p[3][1];
    p[0][0] = XC;
    p[1][0] = YC;
    p[2][0] = 1;
    newcoordinate(s,p);
    XC = p[0][0];
    YC = p[1][0];
}

void maze()
{
    setcolor(WHITE);
    line(100,100,550,100);
    line(150,130,500,130);
    line(200,160,550,160);
    line(250,190,400,190);
    line(200,220,350,220);
    line(150,250,300,250);
    line(100,400,550,400);
    line(100,100,100,150);
    line(100,200,100,400);
    line(150,130,150,370);
    line(200,160,200,220);
    line(200,280,200,400);
    line(250,250,250,370);
    line(300,280,300,400);
    line(350,220,350,370);
    line(400,190,400,400);
    line(450,160,450,370);
    line(500,190,500,400);
    line(550,100,550,370);
    setcolor(YELLOW);
    setcolor(WHITE);
}

void mazeprint()
{
    maze();
    midpoint(XE,YE);
}

int main()
{
	int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    cout<<"\n\n\nMAZE GAME!!!!\n\n\n";
    cout<<"USE ARROW KEYS TO TRAVEL THROUGH MAZE";

    int oldcolour = BLACK,newcolour = RED;
    char arrow1;
    mazeprint();
    midpoint(XC,YC);
    floodfill(XC,YC,newcolour,oldcolour);
    do
    {
        arrow1 = getch();
        switch(arrow1)
        {
            case 72:
            {
                cleardevice();
                translate(0,-10);
                mazeprint();
                midpoint(XC,YC);
                floodfill(XC,YC,newcolour,oldcolour);
                break;
            }
            case 80:
            {
                cleardevice();
                translate(0,10);
                mazeprint();
                midpoint(XC,YC);
                floodfill(XC,YC,newcolour,oldcolour);
                break;
            }
            case 75:
            {
                cleardevice();
                translate(-10,0);
                mazeprint();
                midpoint(XC,YC);
                floodfill(XC,YC,newcolour,oldcolour);
                break;
            }
            case 77:
            {
                cleardevice();
                translate(10,0);
                mazeprint();
                midpoint(XC,YC);
                floodfill(XC,YC,newcolour,oldcolour);
                break;
            }
        }
    }while(XC != XE && YC != YE);
    cleardevice();
    mazeprint();
    floodfill(XE,YE,newcolour,oldcolour);
    cout<<"\n\n\nGAME OVER\n\n\n";

	getch();
	closegraph();
	return 0;
}
