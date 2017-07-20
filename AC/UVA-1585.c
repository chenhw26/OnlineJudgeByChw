#include <stdio.h>
int main()
{
	char OX[81];
	int score,inrow,i,T;
	scanf("%d",&T);
	while(T--)
	{
		inrow=score=0;
		scanf("%s",OX);
		for(i=0;OX[i];i++)
		{
			if(OX[i]=='O')
				score+=++inrow;
			else
				inrow=0;
		}
		printf("%d\n",score);
	}
	return 0;
}