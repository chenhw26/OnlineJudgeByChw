#include <stdio.h>
#include <string.h>
int main()
{
	int T,len,j,i;
	char s[81],sub[81];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		len=strlen(s);
		for(i=1;i<=len;i++)
		{
			if(!(len%i))
			{
				strncpy(sub,s,i);
				for(j=i;s[j];j+=i)
					if(strncmp(sub,s+j,i))
						goto l;
				printf("%d\n",i);
				if(T)
					putchar('\n');
				break;
			}
			l:;
		}
	}
	return 0;
}