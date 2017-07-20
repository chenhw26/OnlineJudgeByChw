#include <stdio.h>
#include <string.h>
int main()
{
	int across[100][2],down[100][2],row,T=0,column,eligible,i,j,flag;
	char puzzle[100][100];
	while(scanf("%d",&row),row)
	{
		memset(across,-1,sizeof(int)*200);
		memset(down,-1,sizeof(int)*200);
		eligible=1;
		scanf("%d",&column);
		getchar();
		for(i=0;i<row;i++)
		{	
			for(j=0;j<column;j++)
			{
				flag=0;
				scanf("%c",&puzzle[i][j]);
				if(puzzle[i][j]!='*'&&(i==0||puzzle[i-1][j]=='*'))
				{
					down[eligible][0]=i;
					down[eligible][1]=j;
					flag=1;
				}
				if(puzzle[i][j]!='*'&&(j==0||puzzle[i][j-1]=='*'))
				{
					across[eligible][0]=i;
					across[eligible][1]=j;
					flag=1;
				}
				if(flag)
					++eligible;
			}
			getchar();
		}
		if(T)
			printf("\n");	
		printf("puzzle #%d:\nAcross\n",++T);
		for(i=1;i<=eligible;i++)
		{
			if(across[i][0]>=0)
			{
				printf("%3d.",i);
				for(j=across[i][1];j<column&&puzzle[across[i][0]][j]!='*';j++)
					putchar(puzzle[across[i][0]][j]);
				putchar('\n');
			}
		}
		puts("Down");
		for(i=1;i<=eligible;i++)
		{
			if(down[i][0]>=0)
			{
				printf("%3d.",i);
				for(j=down[i][0];j<row&&puzzle[j][down[i][1]]!='*';j++)
					putchar(puzzle[j][down[i][1]]);
				putchar('\n');
			}
		}
	}
	return 0;
}