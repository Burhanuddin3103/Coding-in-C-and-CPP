#include<iostream>
#include<conio.h>

using namespace std;

float x[20],y[20],z[20],n;

void newcoordinate(float s[][4], float p[][1])
{
	float temp[4][1] = { 0 };
    int i,j,k;

	for(i = 0; i < 4; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 4; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
	p[2][0] = temp[2][0];
	p[3][0] = temp[3][0];

}

void scale(float x[], float y[], float z[], float sx, float sy, float sz)
{
	float s[4][4] = {sx,0,0,0,0,sy,0,0,0,0,sz,0,0,0,0,1};
	float p[4][1];

	for (int i = 0; i < n; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];
		p[2][0] = z[i];

		newcoordinate(s,p);

		x[i] = p[0][0];
		y[i] = p[1][0];
		z[i] = p[2][0];
	}
}

void reflect_yz(float x[], float y[], float z[], float sx, float sy, float sz)
{
	float s[4][4] = {-1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
	float p[4][1];

	for (int i = 0; i < n; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];
		p[2][0] = z[i];

		newcoordinate(s,p);

		x[i] = p[0][0];
		y[i] = p[1][0];
		z[i] = p[2][0];
	}
}

int main()
{
	int i;
	float sx,sy,sz;
	cout<<"\nEnter the Number of Vertices : ";
    cin>>n;
    cout<<"\nEnter the Co ordinates of points : ";
    for(i=0;i<n;i++)
    {
        cout<<"\npoint "<<i+1<<" :\nx : ";
        cin>>x[i];
        cout<<"\ny : ";
        cin>>y[i];
        cout<<"\nz : ";
        cin>>z[i];
    }

    cout<<"\n1.Scaling";
    cout<<"\nEnter Scaling Factor : \nx : ";
    cin>>sx;
    cout<<"\ny : ";
    cin>>sy;
    cout<<"\nz : ";
    cin>>sz;
    scale(x,y,z,sx,sy,sz);

    cout<<"\n\nCo ordinates of Polygon After Scaling  : ";
    for(i=0;i<n;i++)
    {
        cout<<"\npoint "<<i+1<<" :\nx : "<<x[i];
        cout<<"\ny : "<<y[i];
        cout<<"\nz : "<<z[i];
    }
    scale(x,y,z,1/sx,1/sy,1/sz);

    cout<<"\n\nReflection About YZ Plane";
    reflect_yz(x,y,z,sx,sy,sz);

    cout<<"\n\nCo ordinates of Polygon After Reflection  : ";
    for(i=0;i<n;i++)
    {
        cout<<"\npoint "<<i+1<<" :\nx : "<<x[i];
        cout<<"\ny : "<<y[i];
        cout<<"\nz : "<<z[i];
    }
	return 0;
}
