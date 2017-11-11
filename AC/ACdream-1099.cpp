#include <cstdio>

void swap(int &a, int &b){
	int t = a;
	a = b;
	b = t;
}

int partition(int *p, int n){
	int t = n / 2;
	swap(p[t], p[0]);
	int i = 1, j = n - 1;
	while(i < j){
		for(; i < j && p[j] < p[0]; --j);
		for(; i < j && p[i] > p[0]; ++i);
		if(i < j){
			swap(p[i], p[j]);
			--j;
		}
	}
	swap(p[j], p[0]);
	return j;
}

int maxK(int *p, int n, int k){
	int t = partition(p, n);
	if(t == k)	return p[t];
	if(t < k)	return maxK(p + t + 1, n - t - 1, k - t - 1);
	else	return maxK(p, t, k);
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int *p = new int[n];
	for(int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	printf("%d\n", maxK(p, n, k - 1));
	delete [] p;
	return 0;
}