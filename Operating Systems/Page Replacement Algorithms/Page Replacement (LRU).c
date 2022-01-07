#include<stdio.h>

int LRU(int time[], int n)
{
    int i,min,pos=0;
    min = time[0];
    for(i=1;i<n;i++)
    {
        if(time[i]< min)
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main()
{
    printf("\t\t\tLEAST RECENTLY USED : \n\n");
    int fn,pn,frames[100],c=0,time[100],flag1,flag2,i,j,pos,pf=0;
    fn = 4;
    pn = 10;
    int pages[10] = {4,1,2,2,3,1,2,3,4,1};
    printf("\nNumber of Pages : %d",pn);
    printf("\nNumber of Frames : %d\n\n\n",fn);
    //printf("\nReference String : ");
    for(i=0;i<pn;i++)
        printf("\t%d",pages[i]);
    printf("\n");
    int temp2[fn][pn];
    char temp3[pn];
    for(i=0;i<fn;i++)
    {
        frames[i] = -3;
    }
    for(i=0;i<pn;i++)
    {
        flag1 = flag2 = 0;
        for(j=0;j<fn;j++)
        {
            if(frames[j] == pages[i])
            {
                c++;
                time[j] = c;
                flag1 = flag2 = 1;
                temp3[i] = 'H';
                break;
            }
        }
        if(flag1 == 0)
        {
            for(j=0;j<fn;j++)
            {
                if(frames[j] == -3)
                {
                    c++;
                    pf++;
                    frames[j] = pages[i];
                    time[j] = c;
                    flag2 = 1;
                    temp3[i] = 'P';
                    break;
                }
            }
        }
        if(flag2 == 0)
        {
            pos = LRU(time, fn);
            c++;
            pf++;
            frames[pos] = pages[i];
            time[pos] = c;
            temp3[i] = 'P';
        }
        for(j=0;j<fn;j++)
        {
            temp2[j][i] = frames[j] + 48;
        }
    }
    for(i=0;i<fn;i++)
    {
        printf("\n");
        for(j=0;j<pn;j++)
            printf("\t%c",temp2[i][j]);
    }
    printf("\n");
    for(i=0;i<pn;i++)
        printf("\t%c",temp3[i]);
    printf("\n\nTotal Page Faults : %d",pf);
    return 0;
}
