#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n,m,c,r;
	string wrz[100];
	while(cin>>n){
		for(int i=0;i<60;++i)
			cout<<'-';
		cout<<endl;
		for(int i=m=0;i<n;++i){
			cin>>wrz[i];
			m=max(m,int(wrz[i].length()));
		}
		c=(60-m)/(m+2)+1;
		r=(n-1)/c+1;
		sort(wrz,wrz+n);
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(i+r*j<n){
					cout<<wrz[i+r*j];
					for(int k=wrz[i+r*j].length();k<(j+1==c?m:m+2);++k)
						cout<<' ';
				}
			}
			cout<<endl;
		}
	}
	return 0;
}