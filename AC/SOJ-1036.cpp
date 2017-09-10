#include <stdio.h>
#include <string.h>
int input(char[] ,char[][200]);
void sort(const char[] ,char[][200]);
void decode(const char[] ,char[][200] ,char[][200]);
void output(const char[] ,char[][200]);
int main()
{
    char key[20],origin[100][200],aim[100][200];
    while(input(key,origin))
    {
        sort(key,origin);
        decode(key,origin,aim);
        output(key,aim);
    }
    return 0;   
}
int input(char key[] ,char origin[][200])
{
    char temp[200];
    int keylenth,lenth,i,j,k=0;
    scanf("%s",key);
    if(!strcmp(key,"THEEND"))
        return 0;
    keylenth=strlen(key);
    scanf("%s",temp);
    lenth=strlen(temp);
    for(i=0;i<keylenth;i++)
    {
        for(j=1;j<=lenth/keylenth;j++)
            origin[i][j]=temp[k++];
        origin[i][j]=0;
    }
    return 1;
}
void sort(const char key[] ,char origin[][200])
{
    int i,j,len;
    char temp,sortedkey[20];
    strcpy(sortedkey,key);
    len=strlen(key);
    for(i=1;i<len;i++)
    {
        for(j=i;sortedkey[j]<sortedkey[j-1]&&j>0;j--)
        {
            temp=sortedkey[j];
            sortedkey[j]=sortedkey[j-1];
            sortedkey[j-1]=temp;
        }
    }
    for(i=0;i<len;i++)
        origin[i][0]=sortedkey[i];
}
void decode(const char key[] ,char origin[][200] ,char aim[][200])
{
    int len,i,j;
    len=strlen(key);
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(origin[j][0]==key[i])
            {
                origin[j][0]=0;
                break;
            }
        }
        strcpy(aim[i],&origin[j][1]);
    }
}
void output(const char key[] ,char aim[][200])
{
    int i,j,len;
    len=strlen(key);
    for(i=0;aim[0][i];i++)
    {
        for(j=0;j<len;j++)
            putchar(aim[j][i]);
    }
    putchar('\n');
}                                 