#include<stdio.h>

#define max 999

struct gantt
{
    int pn[max],AT[max],BT[max],FT[max],TT[max],WT[max],PR[max];
}g;

void sort_process(int arr1[],int arr2[],int arr3[],int arr4[],int arr5[],int arr6[],int n)
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
            }
        }
    }
}

void sort_at(int arr1[],int arr2[],int arr3[],int n)
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
            }
        }
    }
}

void sort_bt(int arr1[],int arr2[],int arr3[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for (j=1;j<n-i-1;j++)
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
            }
        }
    }
}

void sjf_pre(int n)
{
    int i;
    float avg=0;
    int at[4] = {0,1,2,3};
    int bt[4] = {7,5,3,1};

    for(i=0;i<n;i++)
    {
        g.AT[i] = at[i];
        g.BT[i] = bt[i];
        g.pn[i] = i+1;
    }
    sort_at(g.BT,g.AT,g.pn,n);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            g.FT[i] = g.BT[i] + g.AT[i];
        }
        else
            g.FT[i] = g.FT[i-1] + g.BT[i] - (g.AT[i-1] - g.AT[i]);
        g.TT[i] = g.FT[i]-g.AT[i];
        g.WT[i] = g.TT[i]-g.BT[i];
    }
    sort_process(g.pn,g.AT,g.BT,g.FT,g.WT,g.TT,n);
    printf("\n\t\tAT\t\tBT\t\tFT\t\tTT\t\tWT");
    for(i=0;i<n;i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",g.pn[i],g.AT[i],g.BT[i],g.FT[i],g.TT[i],g.WT[i]);
        avg = avg + g.WT[i];
    }
    avg = avg/n;
    printf("\n\nAverage Waiting Time : %.2f\n",avg);

}

void print(int n)
{
    int i,j,k,l,m,a=0;
    char gan1[max],gan2[max];
    sort_at(g.AT,g.BT,g.pn,n);
    m=n;
    for(i=1;i<n;i++)
    {
            g.FT[m] = g.BT[i-1] - (g.AT[i] - g.AT[i-1]);
            g.FT[i-1] = g.AT[i] - g.AT[i-1];
            g.pn[m] = g.pn[i-1];
            m++;
    }
    g.FT[n-1] = g.BT[n-1];
    n = m;
    sort_at(g.FT,g.AT,g.pn,n);
    k=0;
    for(i=0;i<n;i++)
    {
        a = a + g.FT[i];
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
        gan2[k] = (a%10) + 48;
        if((a/10)>0)
            gan2[k-1] = (a/10) + 48;

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
    printf("\t\t\t\tSHORTEST JOB FIRST (PREMPTIVE) : ");
    sjf_pre(4);
    print(4);
    return 0;
}
