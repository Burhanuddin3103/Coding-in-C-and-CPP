#include<stdio.h>

#define max 999

struct gantt
{
    int pn[max],AT[max],BT[max],FT[max],TT[max],WT[max],PR[max];
}g;

void sort_process(int arr1[],int arr2[],int arr3[],int arr4[],int arr5[],int arr6[],int arr7[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (arr1[j] > arr1[j+1])
            {
                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;

                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;

                temp = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = temp;

                temp = arr4[j];
                arr4[j] = arr4[j+1];
                arr4[j+1] = temp;

                temp = arr5[j];
                arr5[j] = arr5[j+1];
                arr5[j+1] = temp;

                temp = arr6[j];
                arr6[j] = arr6[j+1];
                arr6[j+1] = temp;

                temp = arr7[j];
                arr7[j] = arr7[j+1];
                arr7[j+1] = temp;
            }
        }
    }
}

void sort_at(int arr1[],int arr2[],int arr3[],int arr4[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (arr1[j] > arr1[j+1])
            {
                temp = arr4[j];
                arr4[j] = arr4[j+1];
                arr4[j+1] = temp;

                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;

                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;

                temp = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = temp;
            }
        }
    }
}

void sort_pr(int arr1[],int arr2[],int arr3[],int arr4[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for (j=1;j<n-i-1;j++)
        {
            if (arr4[j] > arr4[j+1])
            {
                temp = arr4[j];
                arr4[j] = arr4[j+1];
                arr4[j+1] = temp;

                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;

                temp = arr2[j];
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;

                temp = arr3[j];
                arr3[j] = arr3[j+1];
                arr3[j+1] = temp;
            }
        }
    }
}

void pri_non(int n)
{
    int i;
    float avg=0;
    int at[4] = {0,1,2,3};
    int bt[4] = {7,5,3,1};
    int pr[4] = {2,4,3,1};

    for(i=0;i<n;i++)
    {
        g.AT[i] = at[i];
        g.BT[i] = bt[i];
        g.PR[i] = pr[i];
        g.pn[i] = i+1;
    }
    sort_at(g.AT,g.BT,g.pn,g.PR,n);
    sort_pr(g.AT,g.BT,g.pn,g.PR,n);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            g.FT[i] = g.BT[i];
        }
        else
            g.FT[i] = g.FT[i-1] + g.BT[i];
        g.TT[i] = g.FT[i]-g.AT[i];
        g.WT[i] = g.TT[i]-g.BT[i];
    }
    sort_process(g.pn,g.AT,g.BT,g.FT,g.WT,g.TT,g.PR,n);
    printf("\n\t\tPR\t\tAT\t\tBT\t\tFT\t\tTT\t\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",g.pn[i],g.PR[i],g.AT[i],g.BT[i],g.FT[i],g.TT[i],g.WT[i]);
        avg = avg + g.WT[i];
    }
    avg = avg/n;
    printf("\n\nAverage Waiting Time : %.2f\n",avg);
}

void print(int n)
{
    int i,j,k,l;
    char gan1[max],gan2[max];
    sort_at(g.FT,g.pn,g.AT,g.PR,n);
    k=0;
    for(i=0;i<n;i++)
    {
        l=0;
        if(i==0)
        {
            gan2[k] = '0';
            j = g.FT[i];
        }
        else
            j = g.FT[i] - g.FT[i-1];
        gan1[k] = '|';
        k++;
        while(l<=j)
        {
            gan1[k] = ' ';
            gan2[k] = ' ';
            k++;
            l++;
        }
        gan1[k] = 'P';
        gan2[k] = ' ';
        k++;
        gan1[k] = g.pn[i] + 48;
        gan2[k] = ' ';
        k++;
        l=0;
        while(l<=j)
        {
            gan1[k] = ' ';
            gan2[k] = ' ';
            k++;
            l++;
        }
        gan1[k] = '|';
        gan2[k] = (g.FT[i]%10) + 48;
        if((g.FT[i]/10)>0)
            gan2[k-1] = (g.FT[i]/10) + 48;

    }
    k++;
    gan1[k] = '\0';
    gan2[k] = '\0';
    printf("\n\n");
    for(i=0;i<k;i++)
        printf("%c",gan1[i]);
    printf("\n");
    for(i=0;i<k;i++)
        printf("%c",gan2[i]);

}

int main()
{
    printf("\t\t\t\tPRIORITY (NON PREMPTIVE) : \n\n");
    pri_non(4);
    print(4);
    return 0;
}
