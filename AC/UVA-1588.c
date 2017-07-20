#include <stdio.h>
#include <string.h>
int main()
{
	int len,lenm,i,j,min,fail,temp,lenth;
	char master[303],driven[101],m[101];
	while(scanf("%s",m)!=EOF)
	{
		memset(master,0,303*sizeof(char));
		scanf("%s",driven);
		len=strlen(driven);
		lenm=strlen(m);
		if(lenm<len)
		{
			char hold[101];
			strcpy(hold,m);
			strcpy(m,driven);
			strcpy(driven,hold);
			len=strlen(driven);
			lenm=strlen(m);
		}
		for(i=0;i<len;i++)
			master[i]='0';
		strcat(master,m);
		for(;master[i];i++);
		for(j=0;j<len;j++,i++)
			master[i]='0';
		min=lenm+len;
		for(i=0;i<lenm+len;i++)
		{
			for(j=fail=0,temp=i;j<len;j++,temp++)
			{
				if(master[temp]+driven[j]-2*'0'>3)
				{
					fail=1;
					break;
				}
			}
			if(i<len)
				lenth=len+lenm-i;
			else if(i>=len&&i<lenm)
				lenth=lenm;
			else
				lenth=i;
			if(!fail&&lenth<min)
				min=lenth;
		}
		printf("%d\n",min);
	}
	return 0;
}