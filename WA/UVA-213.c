#include <stdio.h>
#include <string.h>
#include <math.h>
int bintodec(char* s ,int len){
	int i=len-1,decimal=0,j=0;
	for(;i>=0;i--,j++)
		decimal+=s[i]=='0'?0:pow(2,j);
	return decimal;
}
int judge(char *s){
	int i;
	for(i=0;s[i];i++)
		if(s[i]=='0')
			return 1;
	return 0;
}
int S(int n){
	return 2*(pow(2,n)-1)-n;
}
void scan(int len ,char *s ){
	int i=0,c;
	while(i<len){
		c=getchar();
		if(c!='0'&&c!='1')
			continue;
		s[i++]=c;
	}
	s[i]=0;
}
int get(char* s){
	int i;
	s[0]=getchar();
	if(s[0]==EOF) return 0;
	for(i=1;s[i-1]!='\n';i++)
		s[i]=getchar();
	s[--i]=0;
	return 1;
}
int main(){
	char header[1000],binary[1000],len;
	while(get(header)){
		while(scanf("%3s",binary),strncmp(binary,"000",3)){
			len=bintodec(binary,3);
			while(scan(len,binary),judge(binary))
				putchar(header[S(len-1)+bintodec(binary,len)]);
		}
		putchar('\n');
		getchar();
	}
	return 0;
}