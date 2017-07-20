#include <stdio.h>
int main(){
	int n,i,j;
	while(~scanf("%d",&n)){
		printf("2 %d %d\n",n,n);
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)
				printf("%c",i>25?'a'+i-26:'A'+i);
			printf("\n");
		}
		printf("\n");
		for(i=0;i<n;++i){
			for(j=0;j<n;++j)
				printf("%c",j>25?'a'+j-26:'A'+j);
			printf("\n");
		}
	}
	return 0;
}