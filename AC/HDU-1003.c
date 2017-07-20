#include <stdio.h>
int main()
{
    int T,test,num[100000],i,max,maxstart,maxtail,numofnum,sum,hold;
    scanf("%d",&T);
    for(test=0;test<T;test++)
    {
        printf("Case %d:\n",test+1);
        scanf("%d",&numofnum);
        for(i=0;i<numofnum;i++)
            scanf("%d",&num[i]);
        max=num[0];
        hold=maxtail=maxstart=1;
        for(i=0,sum=0;i<numofnum;i++)
        {
            sum+=num[i];
            if(sum>max)
            {
                max=sum;
                maxtail=i+1;
                maxstart=hold;
            }
            if(sum<0)
            {
                sum=0;
                hold=i+2;
            }
        }
        if(max<0)
        {
            for(i=0;i<numofnum;i++)
            {
                if(num[i]==max)
                {
                    max=num[i];
                    maxtail=i+1;
                    maxstart=maxtail;
                    goto l1;
                }
            }
        }
        l1:printf("%d %d %d\n",max,maxstart,maxtail);
        if(test!=T-1)
            printf("\n");
    }
    return 0;
}