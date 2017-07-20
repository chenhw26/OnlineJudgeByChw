#include <stdio.h>
#include <string.h>
int main()
{
	char oriDNA[101],temp[101],min[101],hold[101];
	int T,i,len;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",oriDNA);
		strcpy(min,oriDNA);
		len=strlen(oriDNA);
		for(i=1;i<len;i++)
		{
			strcpy(hold,oriDNA);
			strcpy(temp,hold+i);
			hold[i]=0;
			strcat(temp,hold);
			if(strcmp(temp,min)<0)
				strcpy(min,temp);
		}
		printf("%s\n",min);
	}
	return 0;
}