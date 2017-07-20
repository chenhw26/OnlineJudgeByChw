#include <stdio.h>
#include <string.h>
int tot,n,l;
char A[81]={'A'};
int jud(int cur, int c){
	A[cur]=c;
	int i,ok;
	for(i=ok=1;i<=(cur+1)/2;++i){
		if(!strncmp(A+cur-i+1,A+cur+1-i-i,i)){
			ok=0; break;
		}
	}
	if(ok) return 1;
	return 0;
}
void search(int cur, int b){
	if(tot==n){
		int i;
		for(i=0;i<cur;++i){
			putchar(A[i]);
			if((i+1)%64==0) putchar('\n');
			else if(((i+1)%4==0)&&i+1!=cur) putchar(' ');
		}
		if((i+1)%64) putchar('\n');
		printf("%d\n",cur);
	}
	else{
		int i;
		for(i=b;i<l;++i)
			if(jud(cur,i+'A')) break;
		if(i<l){
			++tot;
			search(cur+1,0);
		}
		else search(cur-1,A[cur-1]-'A'+1);
	}
}
int main(){
	while(scanf("%d%d",&n,&l),n){
		tot=1;
		search(1,0);
	}
	return 0;
}