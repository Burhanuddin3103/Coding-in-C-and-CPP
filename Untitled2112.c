#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int position;
bool findc(char type , char c){
        if (type == '[' && c == ']'){
            position++;
            return true;
        }
        if (type == '{' && c == '}'){
            position++;
            return true;
        }
        if (type == '(' && c == ')'){
            position++;
            return true;
        }
        return false;
    };
int main()
{
    char t,text[100],stac[100];
    int l,i=0,x[100],b=0;
    bool m=true;
    gets(text);
    l=strlen(text);
    position=0;
    while(position<l){
        if (text[position] == '(' || text[position] == '[' || text[position] == '{'){
            if (text[position +1] == ')' || text[position +1] == ']' || text[position +1] == '}'){
                m=findc(text[position],text[position +1]);
                position++;
                if(m==false){
                    printf("parenthesis unmatched at position %d",position+1);
                    goto finish;
                }
            }
            else{
                stac[i]=text[position];
                x[i]=position+1;
                i++;
                b++;
                position++;
            }
        }
        else{
            if (text[position] == ')' || text[position] == ']' || text[position] == '}'){
                if(b!=0){
                    t=stac[i-1];
                    i--;
                    b--;
                    m=findc(t,text[position]);
                    if(m==false){
                        printf("parenthesis unmatched at position %d",position+1);
                        goto finish;
                    }
                }
                else{
                    printf("parenthesis unmatched at position %d",position+1);
                    goto finish;
                }
            }
        }
    }
    if(b==0)
        printf("parenthesis matched");
    else
        printf("parenthesis unmatched at position %d",x[0]);
    finish:return 0;
}
