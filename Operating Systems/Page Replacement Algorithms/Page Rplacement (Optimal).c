#include<stdio.h>

int main()
{
    int fn,pn,frames[100],temp[10],flag1,flag2,flag3,i,j,k,pos,max,pf=0;
    printf("\t\t\tOPTIMAL : \n\n");
    fn = 4;
    pn = 10;
    int pages[10] = {4,1,2,5,3,2,5,3,4,1};
    printf("\nNumber of Pages : %d",pn);
    printf("\nNumber of Frames : %d\n\n\n",fn);
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
                    pf++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    temp3[i] = 'P';
                    break;
                }
            }
        }
        if(flag2 == 0)
        {
            flag3 =0;
            for(j=0;j<fn;j++)
            {
                temp[j] = -1;
                for(k=i+1;k<pn;k++)
                {
                    if(frames[j] == pages[k])
                    {
                        temp[j] = k;
                        temp3[i] = 'P';
                        break;
                    }
                }
            }
            for(j=0;j<fn;j++)
            {
                if(temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if(flag3 ==0)
            {
                max = temp[0];
                pos = 0;
                for(j=1;j<fn;j++)
                {
                    if(temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            temp3[i] = 'P';
            pf++;
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
    printf("\n\nTotal Page Faults : %d", pf);
    return 0;
}
