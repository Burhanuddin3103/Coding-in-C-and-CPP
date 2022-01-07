#include <iostream>

using namespace std;

int main()
{
    int i,j,k,y=0;
    cout<<"\t\t\t\t\tBANKER'S ALGORITHM";
    int f[5],ans[5],ind=0,need[5][3];

    int alloc[5][3] = { 0,1,0,
                        2,0,0,
                        3,0,2,
                        2,1,1,
                        0,0,2 };

    int max[5][3] = {   7,5,3,
                        3,2,2,
                        9,0,2,
                        2,2,2,
                        4,3,3 };

    int avail[3] = {3,3,2};

    cout<<"\n\n\n\t\t\tProcess Allocation : \n\n";
    for(i=0;i<3;i++)
    {
        cout<<"\t\tR"<<i;
    }
    for(i=0;i<5;i++)
    {
        cout<<"\nP"<<i;
        for(j=0;j<3;j++)
        {
            cout<<"\t\t"<<alloc[i][j];
        }
    }

    cout<<"\n\n\t\t\tMaximum Allocation : \n\n";
    for(i=0;i<3;i++)
    {
        cout<<"\t\tR"<<i;
    }
    for(i=0;i<5;i++)
    {
        cout<<"\nP"<<i;
        for(j=0;j<3;j++)
        {
            cout<<"\t\t"<<max[i][j];
        }
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    cout<<"\n\n\t\t\tNeed Matrix : \n\n";
    for(i=0;i<3;i++)
    {
        cout<<"\t\tR"<<i;
    }
    for(i=0;i<5;i++)
    {
        cout<<"\nP"<<i;
        for(j=0;j<3;j++)
        {
            cout<<"\t\t"<<need[i][j];
        }
    }


    cout<<"\n\n\t\t\tAvailable Resources : \n\n";
    for(i=0;i<3;i++)
    {
        cout<<"\t\tR"<<i;
    }
    cout<<"\n";
    for(i=0;i<3;i++)
    {
        cout<<"\t\t"<<avail[i];
    }
    cout<<"\n\n\n";
    y=0;
    for(k=0;k<5;k++)
    {
        f[k] = 0;
    }

    for(k=0;k<5;k++)
    {
        for(i=0;i<5;i++)
        {
            int flag;
            if(f[i] == 0)
            {
                for(j=0;j<3;j++)
                {
                    flag = 0;
                    if(need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    cout<<"\n\n\nProcess Satisfied : P"<<i;
                    cout<<"\n\n\t\t\tAvailable Resources : \n\n";
                    for(y=0;y<3;y++)
                    {
                        avail[y] += alloc[i][y];
                        cout<<"\t\t"<<avail[y];
                    }
                    f[i] = 1;
                }
            }
            if(i == 4 && flag == 1)
            {
                printf("\n\nDEADLOCK HAS OCCURED!!!");
                return (0);
            }
        }
    }

    cout<<"\n\nSAFE PROCESS SEQUENCE : \n";
    for(i=0;i<4;i++)
        cout<<" P"<<ans[i]<<" ->";
    cout<<" P"<<ans[4]<<endl;
    return (0);
}
