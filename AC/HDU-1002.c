#include <stdio.h>
#include <string.h>
int main()
{
    int a[1000],b[1000],sum[1000],remain,test=0,get,abit,bbit,sumbit,hold,T;
    scanf("%d",&T);
    getchar();
    for(;test<T;test++)
    {
        printf("Case %d:\n",test+1);
        memset(a,0,sizeof(int)*1000);
        memset(b,0,sizeof(int)*1000);
        memset(sum,0,sizeof(int)*1000);
        abit=bbit=remain=0;
        while((get=getchar())!=' ')
        {
            a[abit++]=get-'0';
            putchar(get);
        }
        printf(" + ");
        while((get=getchar())!='\n')
        {
            b[bbit++]=get-'0';
            putchar(get);
        }
        printf(" = ");
        sumbit=hold=(abit>bbit?abit+1:bbit+1);
        while(abit&&bbit)
        {
            abit--;
            bbit--;
            sumbit--;
            sum[sumbit]=(a[abit]+b[bbit]+remain)%10;
            remain=(a[abit]+b[bbit]+remain)/10;
        }
        if(abit<bbit)
        {
            while(bbit)
            {
                bbit--;
                sumbit--;
                sum[sumbit]=(b[bbit]+remain)%10;
                remain=(b[bbit]+remain)/10;
            }
        }
        else if(bbit<abit)
        {
            
            while(abit)
            {    
                abit--;
                sumbit--;
                sum[sumbit]=(a[abit]+remain)%10;
                remain=(a[abit]+remain)/10;
            }
        }
        if(remain)
            sum[--sumbit]=remain;
        for(;sumbit<hold;sumbit++)
            printf("%d",sum[sumbit]);
        putchar('\n');
        if(test!=T-1)
            putchar('\n');
    }
    return 0;
}