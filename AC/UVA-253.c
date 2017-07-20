#include <stdio.h>
char s[13];
int check(char a ,char b ,char c ,char d){
	if(a==s[7]&&b==s[8]&&c==s[9]&&d==s[10]) return 1;
	if(b==s[7]&&d==s[8]&&a==s[9]&&c==s[10]) return 1;
	if(d==s[7]&&c==s[8]&&b==s[9]&&a==s[10]) return 1;
	if(c==s[7]&&a==s[8]&&d==s[9]&&b==s[10]) return 1;
	return 0;
}
int main(){
	while(~scanf("%s",s)){
		if((s[0]==s[6]&&s[5]==s[11]&&check(s[1],s[2],s[3],s[4]))||
		   (s[1]==s[6]&&s[4]==s[11]&&check(s[5],s[2],s[3],s[0]))||
		   (s[5]==s[6]&&s[0]==s[11]&&check(s[4],s[2],s[3],s[1]))||
		   (s[4]==s[6]&&s[1]==s[11]&&check(s[0],s[2],s[3],s[5]))||
		   (s[2]==s[6]&&s[3]==s[11]&&check(s[1],s[5],s[0],s[4]))||
		   (s[3]==s[6]&&s[2]==s[11]&&check(s[1],s[0],s[5],s[4])))
			puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}