#include <iostream>
#include <map>
using namespace std;
int main(){
	int A[4000],B[4000],C[4000],D[4000];
	int i,j,t,n,ans;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;++i)
			cin>>A[i]>>B[i]>>C[i]>>D[i];
		map<int,int> cnt;
		for(i=0;i<n;++i){
			for(j=0;j<n;++j){
				if(!cnt.count(A[i]+B[j]))
					cnt[A[i]+B[j]]=1;
				else
					++cnt[A[i]+B[j]];
			}
		}
		for(i=ans=0;i<n;++i)
			for(j=0;j<n;++j)
				if(cnt.count(-C[i]-D[j]))
					ans+=cnt[-C[i]-D[j]];
		cout<<ans<<endl;
	}
	return 0;
}