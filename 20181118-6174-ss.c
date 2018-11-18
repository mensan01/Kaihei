#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int operate(int data)
{
    int i,j,length=0;
    char temp;
    int a,b;
    char s[10];
    sprintf(s,"%d",data);
    length=strlen(s);
    for(i=0;i<length;i++){
        for(j=i+1;j<length;j++){
            if (s[i]>s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    sscanf(s,"%d",&b);
    for(i=0;i<length/2;i++)
    {
        temp=s[i];
        s[i]=s[length-1-i];
        s[length-1-i]=temp;
    }
    sscanf(s,"%d",&a);
    return a-b;
}

int main()
{
    int data,count=1;
    int result=0;
    scanf("%d",&data);
    while(count<1000)
    {
        printf("%d->",data);
        result=operate(data);
        if(result == data)
        {
            printf("%d",result);
            break;
        }
        else{
            data=result;
        }
        count++;
    }
    return 0;
}
