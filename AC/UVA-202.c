#include <stdio.h>
int main()
{
	int a,b,remainder,quotient[3000],mod[3000],i,j,k,m;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d/%d = ",a,b);
		j=(i=0)+1;
		remainder=mod[0]=a%b;
		printf("%d.",a/b);
		while(1)
		{
			quotient[i++]=remainder*10/b;
			remainder=mod[j++]=remainder*10%b;
			for(k=0;k<j-1;k++)
				if(remainder==mod[k])
					goto l;
		}
		l:for(m=0;m<k;m++)
		  	  printf("%d",quotient[m]);
		printf("(");
		for(;m<j-1&&m<50;m++)
			printf("%d",quotient[m]);
		if(j-1>50)
			printf("...");
		printf(")\n   %d = number of digits in repeating cycle\n\n",j-1-k);
	}
	return 0;
}