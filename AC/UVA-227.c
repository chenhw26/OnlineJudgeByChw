#include <stdio.h>
void readin(char puzzle[][5] ,int *x ,int *y)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		if(i)
			for(j=0;j<5;j++)
			{
				scanf("%c",&puzzle[i][j]);
				if(puzzle[i][j]==' ')
				{
					*x=i;
					*y=j;
				}
			}
		else
			for(j=1;j<5;j++)
			{
				scanf("%c",&puzzle[i][j]);
				if(puzzle[i][j]==' ')
				{
					*x=i;
					*y=j;
				}
			}
		if(puzzle[i][4]=='\n')
		{
			puzzle[i][4]=' ';
			*x=i;
			*y=4;
		}
		else
			getchar();
	}
}
void move(char puzzle[][5] ,int *spacex ,int *spacey ,int movex ,int movey ,char *flag)
{
	char temp;
	if(*spacex+movex>4||*spacex+movex<0||*spacey+movey<0||*spacey+movey>4)
	{
		*flag=0;
		return;
	}
	temp=puzzle[*spacex][*spacey];
	puzzle[*spacex][*spacey]=puzzle[*spacex+movex][*spacey+movey];
	puzzle[*spacex+movex][*spacey+movey]=temp;
	*spacex+=movex;
	*spacey+=movey;
}
void showpuzzle(char puzzle[][5])
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			printf("%c%c",puzzle[i][j],j==4?'\n':' ');
}
int main()
{
	int x,y,T=0;
	char puzzle[5][5],command,flag;
	while(scanf("%c",&puzzle[0][0]),puzzle[0][0]!='Z')
	{
		if(T)
			printf("\n");
		printf("Puzzle #%d:\n",++T);
		if(puzzle[0][0]==' ')
			x=y=0;
		readin(puzzle,&x,&y);
		flag=1;
		while(scanf("%c",&command),command!='0')
		{
			if(flag)
			{
				switch(command)
				{
					case 'A':
						move(puzzle,&x,&y,-1,0,&flag);
						break;
					case 'B':
						move(puzzle,&x,&y,1,0,&flag);
						break;
					case 'L':
						move(puzzle,&x,&y,0,-1,&flag);
						break;
					case 'R':
						move(puzzle,&x,&y,0,1,&flag);
						break;
					case '\n':
						break;
					default:
						flag=0;
				}
			}
		}
		getchar();
		if(flag)
			showpuzzle(puzzle);
		else
			printf("This puzzle has no final configuration.\n");
	}
	return 0;
}