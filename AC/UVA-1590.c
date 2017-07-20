#include <stdio.h>
int p;
void to_ad(int temp ,int *ad){
	int i;
	for(i=7;i>=0;--i){
		ad[i]=temp%2;
		temp/=2;
	}
}
void cmp(int *net ,int *IP){
	int i;
	for(i=0;IP[i]==net[i];++i);
	if(i<p) p=i;
	for(;i<32;++i)
		IP[i]=0;
}
void show(int* ad){
	int t,i;
	for(i=t=0;i<32;++i){
		t*=2;
		t+=ad[i];
		if((i+1)%8==0){
			printf("%d%c",t,i==31?'\n':'.');
			t=0;
		}
	}
}
int main(){
	int IP[32],net[32],mask[32],n,i,j,temp;
	while(~scanf("%d",&n)){
		p=32;
		for(i=0;i<4;++i){
			getchar();
			scanf("%d",&temp);
			to_ad(temp,IP+i*8);
		}
		for(i=0;i<n-1;++i){
			for(j=0;j<4;++j){
				getchar();
				scanf("%d",&temp);
				to_ad(temp,net+j*8);
			}
			cmp(net,IP);
		}
		show(IP);
		for(i=0;i<32;++i)
			mask[i]=i<p?1:0;
		show(mask);
	}
	return 0;
}