#include <stdio.h>
#include <string.h>
int find(char *s ,char *t )
{
	int i,j=0,find;
	for(i=0;s[i];i++)
	{
		find=0;
		while(t[j])
		{
			if(t[j++]==s[i])
			{
				find=1;
				break;
			}
		}
		if(!find)
			return 0;
	}
	return 1;
}
int main()
{
	char s[100000],t[100000];
	while(scanf("%s %s",s,t)!=EOF)
		printf("%s\n",find(s,t)?"Yes":"No");
	return 0;
}