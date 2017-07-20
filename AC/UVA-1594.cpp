#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
bool chg(int *num, int n){
	int *tmp=new int[n];
	memcpy(tmp,num,sizeof(int)*n);
	for(int i=0;i<n;++i)
		tmp[i]=i==n-1?abs(num[i]-num[0]):abs(num[i]-num[i+1]);
	memcpy(num,tmp,sizeof(int)*n);
	delete [] tmp;
	for(int i=0;i<n;++i)
		if(num[i]) return false;
	return true;
}
bool solve(int *num, int n){
	vector<int> sqnc;
	set<vector<int> > ans;
	while(1){
		sqnc.clear();
		for(int i=0;i<n;++i)
			sqnc.push_back(num[i]);
		if(ans.count(sqnc)) return true;
		ans.insert(sqnc);
		if(chg(num,n)) return false;
	}
}
int main(){
	int T,n,num[15];
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>num[i];
		cout<<(solve(num,n)?"LOOP\n":"ZERO\n");
	} 
	return 0;
}