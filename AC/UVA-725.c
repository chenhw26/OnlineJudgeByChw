#include <stdio.h>
#include <string.h>
int jud(int *ans ,int a ,int b){
	int i;
	for(i=0;i<5;++i){
		++ans[a%10];
		a/=10;
	}
	for(i=0;i<5;++i){
		++ans[b%10];
		b/=10;
	}
	for(i=0;i<10;i++)
		if(!ans[i])
			return 0;
	return 1;
}
int main(){
	int n,i,ans[10],s,t=0;
	while(scanf("%d",&n),n){
		if(t++) printf("\n");
		for(i=1234,s=0;i<=98765;++i){
			if(!(i%n)){
				memset(ans,0,sizeof(int)*10);
				if(jud(ans,i,i/n)){
					printf("%.5d / %.5d = %d\n",i,i/n,n);
					++s;
				}
			}
		}
		if(!s) printf("There are no solutions for %d.\n",n);
	}
	return 0;
}