#include <iostream>
using namespace std;
int main(){
	int N,t,c,f;
	while(cin>>N,N){
		t=c=0;
		while(N--){
			cin>>f;
			t+=f-c>0?6*(f-c)+5:4*(c-f)+5;
			c=f;
		}
		cout<<t<<endl;
	}
	return 0;
}
