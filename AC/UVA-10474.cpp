#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,q,a[10000],t,k=0,p;
	while(cin>>n>>q,n){
		cout<<"CASE# "<<++k<<":\n";
		for(int i=0;i<n;++i)
			cin>>a[i];
		sort(a,a+n);
		while(q--){
			cin>>t;
			if(a[p=lower_bound(a,a+n,t)-a]==t)
				cout<<t<<" found at "<<p+1<<endl;
			else
				cout<<t<<" not found\n";
		}
	}
	return 0;
}