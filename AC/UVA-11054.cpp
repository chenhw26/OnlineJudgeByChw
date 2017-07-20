#include <iostream>
#include <cmath>
using namespace std;
long long wrk(long long *vlg, long long cur, long long n){
	if(cur==n-1)
		return abs(vlg[cur-1]);
	else
		vlg[cur]+=vlg[cur-1];
	return abs(vlg[cur-1])+wrk(vlg,cur+1,n);
}
int main(){
	long long vlg[100000],n;
	while(cin>>n,n){
		for(long long i=0;i<n;++i)
			cin>>vlg[i];
		cout<<wrk(vlg,1,n)<<endl;
	}
	return 0;
}