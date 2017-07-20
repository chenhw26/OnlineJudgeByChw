#include <stdio.h>
#include <string.h>
int main()
{
	char s[101],t[101];
	int frequencys[26],frequencyt[26],i,s100[101],t100[101];
	while(~scanf("%s%s",s,t))
	{
		memset(frequencys,0,26*sizeof(int));
		memset(frequencyt,0,26*sizeof(int));
		memset(s100,0,101*sizeof(int));
		memset(t100,0,101*sizeof(int));
		for(i=0;s[i];i++)
			frequencys[s[i]-'A']++;
		for(i=0;t[i];i++)
			frequencyt[t[i]-'A']++;
		for(i=0;i<26;i++)
			s100[frequencys[i]]++;
		for(i=0;i<26;i++)
			t100[frequencyt[i]]++;
		printf("%s\n",memcmp(s100,t100,sizeof(int)*101)?"NO":"YES");
	}
	return 0;
}