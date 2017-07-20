#include <iostream>
#include <stack>
using namespace std;
bool jud(int *ori, int N){
	for(int i=0;i<N-1;++i)
		if(ori[i+1]-ori[i]<0) return false;
	return true;
}
int main(){
	int N;
	while(cin>>N,N){
		int *trn=new int[N],*ori=new int[N];
		while(cin>>trn[0],trn[0]){
			for(int i=1;i<N;++i)
				cin>>trn[i];
			stack<int> s;
			int j=N-1;
			for(int i=N-1;i>=0;--i){
				while(!s.empty()&&s.top()>trn[i]){
					ori[j--]=s.top();
					s.pop();
				}
				s.push(trn[i]);
			}
			while(!s.empty()){
				ori[j--]=s.top();
				s.pop();
			}
			cout<<(jud(ori,N)?"Yes\n":"No\n");
		}
		delete [] trn;
		cout<<endl;
	}
	return 0;
}