#include <iostream>
#include <map>
using namespace std;
int main(){
	int t,n,l,r,max,cnt;
	cin>>t;
	while(t--){
		map<int,int> ans;
		cin>>n;
		int *snflk=new int[n];
		for(int i=0;i<n;++i)
			cin>>snflk[i];
		ans[snflk[0]]=1;
		for(l=0,r=cnt=max=1;r<n;){
			if(ans.count(snflk[r])&&ans[snflk[r]]){
				ans[snflk[l++]]=0;
				cnt--;
			}
			else{ 
				++cnt;
				if(cnt>max)
					max=cnt;
				ans[snflk[r++]]=1;
			}
		}
		cout<<max<<endl;
		delete [] snflk;
	}
	return 0;
}