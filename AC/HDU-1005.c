#include <stdio.h>
int main()
{
    int A,B,n,f[50]={1,1},i;
    while(scanf("%d%d%d",&A,&B,&n),A)
    {
        for(i=2;i<50;i++)
        {
            f[i]=(A*f[i-1]+B*f[i-2])%7;
            if(f[i]==1&&f[i-1]==1)
                break;
        }
        printf("%d\n",n%(i-1)?f[n%(i-1)-1]:f[i-2]);
    }
    return 0;
}