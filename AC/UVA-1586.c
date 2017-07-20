#include <stdio.h>
#include <ctype.h>
int main()
{
	char formula[81],temp;
	int i,T,count;
	double mass,weight['O'+1];
	weight['C']=12.01;
	weight['H']=1.008;
	weight['N']=14.01;
	weight['O']=16.00;
	scanf("%d",&T);
	while(T--)
	{
		mass=0;
		scanf("%s",formula);
		for(i=0;formula[i];i++)
		{
			temp=formula[i];
			count=0;
			while(isdigit(formula[i+1]))
				count=count*10+formula[++i]-'0';
			mass+=weight[temp]*(count?count:1);
		}
		printf("%.3lf\n",mass);
	}
	return 0;
}