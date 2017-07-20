#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n;
	while(cin>>n,n){
		queue<int> crds;
		for(int i=0;i<n;++i)
			crds.push(i+1);
		int t=0;
		cout<<"Discarded cards:";
		while(crds.size()>1){
			if(t++) cout<<", "<<crds.front();
			else cout<<' '<<crds.front();
			crds.pop();
			crds.push(crds.front());
			crds.pop();
		}
		cout<<"\nRemaining card: "<<crds.front()<<endl;;
	}
	return 0;
}