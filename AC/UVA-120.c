#include <stdio.h>
void sort(int *pnc, int cur, int n){
	if(cur){
		int i,max=pnc[cur],t=cur;
		for(i=cur-1;i>=0;--i){
			if(pnc[i]>max){
				t=i;
				max=pnc[i];
			}
		}
		if(t!=cur){
			if(t){
				printf("%d ",n-t+1);
				rvr(pnc,t);
			}
			printf("%d ",n-cur+1);
			rvr(pnc,cur);
		}
		sort(pnc,cur-1,n);
	}
}
void rvr(int *pnc, int k){
	int i=0,t;
	for(;i<=k/2;++i){
		t=pnc[i];
		pnc[i]=pnc[k-i];
		pnc[k-i]=t;
	}
}
int main(){
	int n,pnc[30],i;
	while(~scanf("%d",&pnc[0])){
		n=0;
		while(getchar()!='\n')
			scanf("%d",&pnc[++n]);
		for(i=0;i<=n;++i)
			printf("%d%c",pnc[i],i==n?'\n':' ');
		sort(pnc,n,n);
		printf("0\n");
	}
	return 0;
}