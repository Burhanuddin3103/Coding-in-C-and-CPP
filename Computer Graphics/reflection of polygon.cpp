#include<iostream>
#include<conio.h>
#include<graphics.h>

using namespace std;

int x[20],y[20],n;

void dda(int n)
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

void reflectx(int x[], int y[])
{
	/*for reflection about line x=y : s[3][3] = {0,1,0,1,0,0,0,0,1}
	  for reflection about x axis : s[3][3] = {1,0,0,0,-1,0,0,0,1}
      for reflection about y axis : s[3][3] = {-1,0,0,0,1,0,0,0,1}
      for reflection about xy plane : s[3][3] = {-1,0,0,0,-1,0,0,0,1}*/
	int s[3][3] = {0,1,0,1,0,0,0,0,1};
	int p[3][1];

	for (int i = 0; i < 3; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];

		newcoordinate(s,p);

		x[i] = p[0][0];
		y[i] = p[1][0];
	}

	dda(n);
}

int main()
{
	int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	int i;
	cout<<"\nEnter the Number of Vertices : ";
    cin>>n;
    cout<<"\nEnter the Co ordinates of points : ";
    for(i=0;i<n;i++)
    {
        cout<<"\npoint "<<i+1<<" :\nx : ";
        cin>>x[i];
        cout<<"\ny : ";
        cin>>y[i];
    }
    dda(n);
    reflectx(x,y);

	getch();
	return 0;
}
