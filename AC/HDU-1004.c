#include <stdio.h>
#include <string.h>
typedef struct 
{
    char color[20];
    int amount;
} balloon;
int main()
{
    balloon ball[100];
    char tempcolar[20];
    int N,i,j,max,hold;
    while(scanf("%d",&N),N)
    {
        memset(ball,0,sizeof(balloon)*100);
        for(i=0;i<N;i++)
        {
            scanf("%s",tempcolar);
            for(j=0;ball[j].color[0]&&j<100;j++)
            {
                if(strcmp(tempcolar,ball[j].color)==0)
                {
                    ball[j].amount++;
                    tempcolar[0]=0;
                    break;
                }
            }
            if(tempcolar[0])
            {
                strcpy(ball[j].color,tempcolar);
                ball[j].amount++;
            }
        }
        max=ball[0].amount;
        hold=0;
        for(i=0;ball[i].color[0];i++)
        {
            if(ball[i].amount>max)
            {
                hold=i;
                max=ball[i].amount;
            }
        }
        printf("%s\n",ball[hold].color);
    }
    return 0;
}