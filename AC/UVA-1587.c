#include <stdio.h>
#include <string.h>
int solve(int rectangle[][3])
{
	int i=5,j=1,w,h,k,identical,fail=0;
	while(i--)
	{
		identical=0;
		scanf("%d%d",&w,&h);
		for(k=0;k<j;k++)
		{
			if(rectangle[k][2]<2&&(((w==rectangle[k][0]&&h==rectangle[k][1]))||(w==rectangle[k][1]&&h==rectangle[k][0])))
			{
				identical=1;
				rectangle[k][2]++;
			}
		}
		if(!identical&&j==3)
			fail=1;
		else if(!identical&&j<3)
		{
			rectangle[j][0]=w;
			rectangle[j][1]=h;
			rectangle[j++][2]=1;
		}
	}
	if(fail)
		return 0;
	fail=1;
	if(rectangle[0][0]==rectangle[1][0])
	{
		if(rectangle[0][1]==rectangle[2][0]&&rectangle[1][1]==rectangle[2][1])
			fail=0;
		if(rectangle[0][1]==rectangle[2][1]&&rectangle[1][1]==rectangle[2][0])
			fail=0;
	}
	if(rectangle[0][1]==rectangle[1][0])
	{
		if(rectangle[0][0]==rectangle[2][0]&&rectangle[1][1]==rectangle[2][1])
			fail=0;
		if(rectangle[0][0]==rectangle[2][1]&&rectangle[1][1]==rectangle[2][0])
			fail=0;
	}
	if(rectangle[0][1]==rectangle[1][1])
	{
		if(rectangle[0][0]==rectangle[2][0]&&rectangle[1][0]==rectangle[2][1])
			fail=0;
		if(rectangle[0][0]==rectangle[2][1]&&rectangle[1][0]==rectangle[2][0])
			fail=0;
	}
	if(rectangle[0][0]==rectangle[1][1])
	{
		if(rectangle[0][1]==rectangle[2][0]&&rectangle[1][0]==rectangle[2][1])
			fail=0;
		if(rectangle[0][1]==rectangle[2][1]&&rectangle[1][0]==rectangle[2][0])
			fail=0;
	}
	return !fail;
}
int main()
{
	int rectangle[3][3];
	while(scanf("%d",&rectangle[0][0])!=EOF)
	{
		rectangle[0][2]=(rectangle[1][2]=rectangle[2][2]=0)+1;
		scanf("%d",&rectangle[0][1]);
		printf("%s\n",solve(rectangle)?"POSSIBLE":"IMPOSSIBLE");
		memset(rectangle,0,sizeof(int)*9);
	}
	return 0;
}