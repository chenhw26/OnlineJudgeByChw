#include <iostream>
#include <queue>
#include <map>
using namespace std;
int main(){
	int t,k=0,n,elmt;
	while(cin>>t,t){
		cout<<"Scenario #"<<++k<<endl;
		map<int,int> tm;
		queue<int> q,*qt=new queue<int>[t];
		for(int i=0;i<t;++i){
			cin>>n;
			for(int j=0;j<n;++j){
				cin>>elmt;
				tm[elmt]=i;
			}
		}
		char cmd[10];
		while(cin>>cmd,cmd[0]!='S'){
			if(cmd[0]=='E'){
				cin>>elmt;
				if(qt[tm[elmt]].empty()) q.push(tm[elmt]);
				qt[tm[elmt]].push(elmt);
			}
			else if(cmd[0]=='D'){
				int curt=q.front();
				cout<<qt[curt].front()<<endl;
				qt[curt].pop();
				if(qt[curt].empty()) q.pop();
			}
		}
		cout<<endl;
		delete [] qt;
	}
	return 0;
}