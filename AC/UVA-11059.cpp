#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int N,num[18],t=0;
	long double ans,max;
	while(cin>>N){
		for(int i=0;i<N;++i)
			cin>>num[i];
		for(int i=max=0;i<N;++i){
			ans=1;
			for(int j=i;j<N;++j){
				ans*=num[j];
				if(ans>max)
					max=ans;
			}
		}
		cout<<"Case #"<<++t<<": The maximum product is "<<fixed<<setprecision(0)<<max<<".\n\n";
	}
	return 0;
}