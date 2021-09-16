#include<iostream>
#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int xmin, xmax, ymin, ymax;

typedef struct lines l;
struct lines
{
	int x1, y1, x2, y2;
};

int sign(int x)
{
	if (x > 0)
		return 1;
	else
		return 0;
}

void clip(l mylines)
{
	int bits[4], bite[4], i, var;
	setcolor(YELLOW);

	bits[0] = sign(xmin - mylines.x1);
	bite[0] = sign(xmin - mylines.x2);
	bits[1] = sign(mylines.x1 - xmax);
	bite[1] = sign(mylines.x2 - xmax);
	bits[2] = sign(ymin - mylines.y1);
	bite[2] = sign(ymin - mylines.y2);
	bits[3] = sign(mylines.y1 - ymax);
	bite[3] = sign(mylines.y2 - ymax);

	string initial = "", end = "", temp = "";

	for (i = 0; i < 4; i++)
    {
		if (bits[i] == 0)
			initial += '0';
		else
			initial += '1';
	}
	for (i = 0; i < 4; i++)
	{
		if (bite[i] == 0)
			end += '0';
		else
			end += '1';
	}

	float m = (mylines.y2 - mylines.y1) / (float)(mylines.x2 - mylines.x1);
	float c = mylines.y1 - m * mylines.x1;

	if (initial == end && end == "0000")
    {
		line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
		return;
	}
	else
    {
		for (i = 0; i < 4; i++)
		{

			int val = (bits[i] & bite[i]);
			if (val == 0)
				temp += '0';
			else
				temp += '1';
		}
		if (temp != "0000")
			return;
		for (i = 0; i < 4; i++)
        {
			if (bits[i] == bite[i])
				continue;
			if (i == 0 && bits[i] == 1)
			{
				var = round(m * xmin + c);
				mylines.y1 = var;
				mylines.x1 = xmin;
			}
			if (i == 0 && bite[i] == 1)
			{
				var = round(m * xmin + c);
				mylines.y2 = var;
				mylines.x2 = xmin;
			}
			if (i == 1 && bits[i] == 1)
			{
				var = round(m * xmax + c);
				mylines.y1 = var;
				mylines.x1 = xmax;
			}
			if (i == 1 && bite[i] == 1)
			{
				var = round(m * xmax + c);
				mylines.y2 = var;
				mylines.x2 = xmax;
			}
			if (i == 2 && bits[i] == 1)
			{
				var = round((float)(ymin - c) / m);
				mylines.y1 = ymin;
				mylines.x1 = var;
			}
			if (i == 2 && bite[i] == 1)
			{
				var = round((float)(ymin - c) / m);
				mylines.y2 = ymin;
				mylines.x2 = var;
			}
			if (i == 3 && bits[i] == 1)
			{
				var = round((float)(ymax - c) / m);
				mylines.y1 = ymax;
				mylines.x1 = var;
			}
			if (i == 3 && bite[i] == 1)
			{
				var = round((float)(ymax - c) / m);
				mylines.y2 = ymax;
				mylines.x2 = var;
			}
			bits[0] = sign(xmin - mylines.x1);
			bite[0] = sign(xmin - mylines.x2);
			bits[1] = sign(mylines.x1 - xmax);
			bite[1] = sign(mylines.x2 - xmax);
			bits[2] = sign(ymin - mylines.y1);
			bite[2] = sign(ymin - mylines.y2);
			bits[3] = sign(mylines.y1 - ymax);
			bite[3] = sign(mylines.y2 - ymax);
		}

		initial = "", end = "";

		for (i = 0; i < 4; i++)
        {
			if (bits[i] == 0)
				initial += '0';
			else
				initial += '1';
		}
		for (i = 0; i < 4; i++)
		{
			if (bite[i] == 0)
				end += '0';
			else
				end += '1';
		}
		if (initial == end && end == "0000")
		{
			line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
			return;
		}
		else
			return;
	}
}

main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"");

	int n,i;

	cout<<"\nEnter the Limits of the Clipping Window ";
	cout<<"\nx min : ";
	cin>>xmin;
	cout<<"\nx max : ";
	cin>>xmax;
	cout<<"\ny min : ";
	cin>>ymin;
	cout<<"\ny max : ";
	cin>>ymax;

	setcolor(RED);
	line(xmin, ymin, xmax, ymin);
	line(xmax, ymin, xmax, ymax);
	line(xmax, ymax, xmin, ymax);
	line(xmin, ymax, xmin, ymin);

	cout<<"\nEnter the number of Lines : ";
	cin>>n;

	struct lines mylines[n];

	cout<<"\nEnter the Co-ordinates of the Lines : ";
	for(i=0;i<n;i++)
    {
        cout<<"\nLine : "<<i+1<<"\nx1 : ";
        cin>>mylines[i].x1;
        cout<<"\ny1 : ";
        cin>>mylines[i].y1;
        cout<<"\nx2 : ";
        cin>>mylines[i].x2;
        cout<<"\ny2 : ";
        cin>>mylines[i].y2;
    }

	for (int i = 0; i < n; i++)
    {
		setcolor(WHITE);
		line(mylines[i].x1 , mylines[i].y1 , mylines[i].x2 , mylines[i].y2);
	}
	for (int i = 0; i < n; i++)
    {
		clip(mylines[i]);
	}
	getch();
	closegraph();
}
