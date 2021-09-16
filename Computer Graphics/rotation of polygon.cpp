#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>

using namespace std;

float x[20],y[20];
int n;

void dda(int n)
{
    int j,a=0,i=0;
    float X,Y,dx,dy,s,k;
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

void newcoordinate(float s[][3], float p[][1])
{
	float temp[3][1] = { 0 };
    int i,j,k;

	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
	p[2][0] = temp[2][0];
}

void rotation(float x[], float y[], float theta)
{
	float s[3][3] = {cos(theta),-sin(theta),0,sin(theta),cos(theta),0,1,1,1};
	float p[3][1];

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
	float theta;
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

    cout<<"\nEnter the Angle of Rotation : \ntheta : ";
    cin>>theta;
    rotation(x,y,theta);
    for(i=0;i<n;i++)
    {
        cout<<"\npoint "<<i+1<<" :\nx : "<<x[i];
        cout<<"\ny : "<<y[i];
    }
	getch();
	return 0;
}
