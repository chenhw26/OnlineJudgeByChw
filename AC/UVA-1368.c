#include <stdio.h>
#include <string.h>
int main()
{
	int T,row,column,distance,i,j,frequency[1000]['T'-'A'+1],max;
	char DNA[51][1001],letter;
	scanf("%d",&T);
	while(T--)
	{
		distance=0;
		scanf("%d%d",&row,&column);
		memset(frequency,0,sizeof(int)*column*('T'-'A'+1));
		getchar();
		for(i=0;i<row;i++)
		{
			for(j=0;j<column;j++)
			{
				scanf("%c",&DNA[i][j]);
				frequency[j][DNA[i][j]-'A']++;
			}
			getchar();
		}
		for(j=0;j<column;j++)
		{
			max=0;
			for(i=0;i<'T'-'A'+1;i++)
			{
				if(frequency[j][i]>max)
				{
					max=frequency[j][i];
					letter=i;
				}
				distance+=frequency[j][i];
			}
			putchar(letter+'A');
			distance-=max;
		}
		printf("\n%d\n",distance);
	}
	return 0;
}