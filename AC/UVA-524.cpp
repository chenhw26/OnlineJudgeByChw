#include <iostream>
using namespace std;
int prime[33],v[17]={0,1};
int is_prime(int n){
	if(n==1) return 0;
	for(int i=2;i*i<=n;++i)
		if(n%i==0) return 0;
	return 1;
}
void arr(int n, int *A, int cur){
	if(cur==n){
		if(prime[A[cur-1]+A[0]])
			for(int i=0;i<n;++i)
				cout<<A[i]<<(i==n-1?'\n':' ');
	}
	else{
		for(int i=2;i<=n;++i){
			if(!v[i]&&prime[i+A[cur-1]]){
				v[i]=1;
				A[cur]=i;
				arr(n,A,cur+1);
				v[i]=0;
			}
		}
	}
}
int main(){
	for(int i=1;i<33;++i)
		prime[i]=is_prime(i);
	int A[16]={1},n,t=0;
	while(cin>>n){
		if(t) cout<<endl;
		cout<<"Case "<<++t<<":\n";
		arr(n,A,1);
	}
	return 0;
}