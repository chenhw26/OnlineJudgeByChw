#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	double a[10][31];
	long b[10][31];
	int M,E;
	for(M=0;M<10;M++)
	{
		for(E=1;E<31;E++)
		{
			b[M][E]=(long)(log10((1-pow(2,-M-1))*pow(2,pow(2,E)-1)));
			a[M][E]=log10((1-pow(2,-M-1))*pow(2,pow(2,E)-1))-b[M][E];
		}
	}
	char s[100];
	l:while(scanf("%s",s),strcmp(s,"0e0"))
	{
		int i;
		long B;
		double A;
		for(i=0;s[i]!='e';i++);
		s[i]=0;
		B=atol(s+i+1);
		A=atof(s);	
		while(A<1){A*=10;--B;}
		for(M=0;M<10;M++)
		{
			for(E=1;E<31;E++)
			{
				if(fabs(log10(A)-a[M][E])<10e-4&&B==b[M][E])
				{
					printf("%d %d\n",M,E);
					goto l;
				}
			}
		}
	}
	return 0;
}