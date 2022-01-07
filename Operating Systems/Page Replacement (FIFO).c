#include <stdio.h>

int main()
{
    printf("\t\t\tFIRST IN FIRST OUT : \n\n");
    int pf=0,i,j,s,pages,frames;
    pages = 10;
    frames = 4;
    int str[10] = {4,1,2,3,5,2,3,1,4,2};
    printf("\nNumber of Pages : %d",pages);
    printf("\nNumber of Frames : %d\n\n\n",frames);
    //printf("\nReference String : ");
    for(i=0;i<pages;i++)
        printf("\t%d",str[i]);
    printf("\n");
    int temp[frames];
    int temp2[frames][pages];
    char temp3[pages];
    for(i=0;i<frames;i++)
    {
        temp[i] = -3;
    }
    for(i=0;i<pages;i++)
    {
        s = 0;
        for(j=0;j<frames;j++)
        {
            if(str[i] == temp[j])
            {
                s++;
                pf--;
                temp3[i] = 'H';
            }
        }
        pf++;
        if((pf <= frames) && (s == 0))
        {
            temp[i] = str[i];
            temp3[i] = 'P';
        }
        else if(s == 0)
        {
            temp[(pf - 1) % frames] = str[i];
            temp3[i] = 'P';
        }
        for(j=0;j<frames;j++)
        {
            temp2[j][i] = temp[j] + 48;
        }
    }
    for(i=0;i<frames;i++)
    {
        printf("\n");
        for(j=0;j<pages;j++)

            printf("\t%c",temp2[i][j]);
    }
    printf("\n");
    for(i=0;i<pages;i++)
        printf("\t%c",temp3[i]);
    printf("\n\nTotal Page Faults : %d",pf);
    return 0;
}
