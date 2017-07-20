#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
	int n,rmn,A,B;
	while(cin>>n,n){
		map<vector<int>,int> ans;
		rmn=0;
		while(n--){
			vector<int> cdt;
			cin>>A>>B;
			cdt.push_back(B);
			cdt.push_back(A);
			if(ans.count(cdt)&&ans[cdt])
				--ans[cdt],--rmn;
			else{
				cdt.clear();
				cdt.push_back(A);
				cdt.push_back(B);
				if(ans.count(cdt)) ++ans[cdt];
				else ans[cdt]=1;
				++rmn;
			}
		}
		if(rmn) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}