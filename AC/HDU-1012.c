#include <stdio.h>
int main(){
	int f[10]={1},i;
	double e[10]={1};
	for(i=1;i<10;++i) f[i]=f[i-1]*i;
	for(i=1;i<10;++i) e[i]=e[i-1]+(double)1/f[i];
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(i=3;i<10;++i) printf("%d %.9lf\n",i,e[i]);
	return 0;
}