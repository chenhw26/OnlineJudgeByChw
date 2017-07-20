#include <stdio.h>
#include <string.h>
int main(){
	int n,k,m,left,A,B,move[21],T,i;
	while(scanf("%d%d%d",&n,&k,&m),n){
		memset(move,0,sizeof(int)*21);
		B=(left=n)+1;
		A=T=0;
		while(left){
			i=k;
			while(i){
				++A;
				if(A>n)
					A-=n;
				if(!move[A])
					i--;
			}
			i=m;
			while(i){
				--B;
				if(B<1)
					B+=n;
				if(!move[B])
					i--;
			}
			if(A==B){
				--left;
				if(T++)
					putchar(',');
				printf("%3d",A);
				move[A]=1;
			}
			else{
				left-=2;
				if(T++)
					putchar(',');
				printf("%3d%3d",A,B);
				move[A]=move[B]=1;
			}
		}
		putchar('\n');
	}
	return 0;
}