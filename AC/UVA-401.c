#include <stdio.h>
#include <string.h>
#include <ctype.h>
char reverse(char c)
{
	char *re="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	if(c>='A'&&c<='Z')
		return re[c-'A'];
	if(isdigit(c))
		return re[c-'0'+25];
	return 0;
}
int main()
{
	char s[20],*message[4]={"is not a palindrome","is a regular palindrome","is a mirrored string","is a mirrored palindrome"};
	int i,len,ismirrored,ispalindrome;
	while(scanf("%s",s)!=EOF)
	{
		len=strlen(s);
		for(i=0,ispalindrome=ismirrored=1;i<(len+1)/2;i++)
		{
			if(s[i]!=s[len-1-i])
				ispalindrome=0;
			if(reverse(s[i])!=s[len-1-i])
				ismirrored=0;
			if(ismirrored==0&&ispalindrome==0)
				break;
		}
		printf("%s -- %s.\n\n",s,message[ismirrored*2+ispalindrome]);
	}
	return 0;
}