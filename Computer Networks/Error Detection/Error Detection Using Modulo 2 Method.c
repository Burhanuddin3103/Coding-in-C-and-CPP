#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char* xor(char a[],char b[])
{
    int n,i;
    n = strlen(b);
    char *res;
    free(res);
    res = (char *)malloc(sizeof(char)*n);
    for(i=0;i<n;i++)
    {
        if(a[i] == b[i])
            *(res+i)= '0';
        else
            *(res+i)= '1';
    }
    *(res+i) = '\0';
    return res;
}

char* moddiv(char divident[],char divisor[])
{
    int n,divslen,i,s;
    divslen = strlen(divisor);
    s = strlen(divisor);
    char *temp1,*temp2;
    free(temp1);
    free(temp2);
    temp1 = (char *)malloc(sizeof(char)*s);
    temp2 = (char *)malloc(sizeof(char)*s);
    n = strlen(divident);


    for(i=0;i<divslen;i++)
        temp1[i] = divident[i];
    temp1[i] = '\0';
    while (divslen < n)
	{
		if (temp1[0] == '1')
        {
			strcpy(temp1,xor(divisor,temp1));
			for(i=0;i<s-1;i++)
            {
                temp1[i] = temp1[i+1];
            }
            temp1[s-1] = divident[divslen];
        }
		else
        {
			for(int i=0;i<divslen;i++)
                temp2[i] = '0';
			strcpy(temp1,xor(temp2, temp1));
			for(i=0;i<s-1;i++)
            {
                temp1[i] = temp1[i+1];
            }
            temp1[s-1] = divident[divslen];
        }
		divslen += 1;
	}
	if (temp1[0] == '1')
    {
		strcpy(temp1,xor(divisor, temp1));
		for(i=0;i<s-1;i++)
        {
            temp1[i] = temp1[i+1];
        }
        temp1[s-1] = divident[divslen];
    }
	else
    {
        for(int i=0;i<divslen;i++)
            temp2[i] = '0';
        strcpy(temp1,xor(temp2,temp1));
        for(i=0;i<s-1;i++)
        {
            temp1[i] = temp1[i+1];
        }
        temp1[s-1] = divident[divslen];
    }
	return temp1;
}

void encode(char data[],char key[])
{
    int keylen,datalen,i,j,l;
    keylen = strlen(key);
    datalen = strlen(data);
    l = keylen+datalen-1;

    char rem[keylen];
    char newdata[l],code[l];

    strcpy(newdata,data);
	for(i=datalen;i<l;i++)
        newdata[i] = '0';
    newdata[i] = '\0';
	strcpy(rem,moddiv(newdata,key));
	strcpy(code,data);
	for(i=datalen,j=0;i<l;i++,j++)
        code[i] = rem[j];
    code[i] = '\0';
    printf("\n\t\t\t\tSender's Side : ");
    printf("\n\nData : %s",data);
    printf("\nKey : %s",key);
    printf("\nRemainder : %s",rem);

    strcpy(rem,moddiv(code,key));

    printf("\n\n\t\t\t\tReceivers's Side : ");
    printf("\n\nEncoded Data : %s",code);
    printf("\nKey : %s",key);
    printf("\nRemainder : %s",rem);

    for(i=0;i<keylen-1;i++)
    {
        if(rem[i] == '1')
        {
            printf("\n\n\t\t\t\t!!!ERROR IN TRANSMISSION!!!");
            break;
        }
    }
    if(i==(keylen-1))
        printf("\n\n\t\t\t\tTRANSMISSION SUCCESSFUL\n");
}

int main()
{
    char data[100],key[100];
    printf("\nEnter the Message : ");
    gets(data);
    printf("\nEnter the Key : ");
    gets(key);
	encode(data,key);
	return 0;
}
