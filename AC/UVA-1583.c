#include <stdio.h>
int main()
{
	int T,num,i,a,b,ans[100100]={0};
	for(i=1;i<=100000;i++)
	{
		a=b=i;
		while(a)
		{
			b+=a%10;
			a/=10;
		}
		if(!ans[b])
			ans[b]=i;
	}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&num);
		printf("%d\n",ans[num]);
	}
	return 0;
}