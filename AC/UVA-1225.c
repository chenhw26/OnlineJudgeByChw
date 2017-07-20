#include <stdio.h>
#include <string.h>
int main()
{
	int i,T,count[10],num,temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&num);
		memset(count,0,sizeof(int)*10);
		for(i=1;i<=num;i++)
		{
			temp=i;
			while(temp)
			{
				count[temp%10]++;
				temp/=10;
			}
		}
		for(i=0;i<10;i++)
			printf("%d%c",count[i],i==9?'\n':' ');
	}
	return 0;
}