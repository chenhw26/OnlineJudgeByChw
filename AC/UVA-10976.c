#include <stdio.h>
int main(){
	int k,y,c;
	while(~scanf("%d",&k)){
		for(y=k+1,c=0;y<=2*k;++y){
			if(!(k*y%(y-k)))
				++c;
		}
		printf("%d\n",c);
		for(y=k+1;y<=2*k;++y){
			if(!(k*y%(y-k)))
				printf("1/%d = 1/%d + 1/%d\n",k,k*y/(y-k),y);
		}
	}
	return 0;
}