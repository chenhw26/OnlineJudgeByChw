#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;
int r1,c1,r2,c2,n,m;
bool solve(void){
	int dtbs[10000][10],c=0;
	char t;
	string tmp,tmp2;
	map <string,int> fnc;
	cin.get();
	for(int i=0;i<n;++i){
		getline(cin,tmp);
		int len=tmp.length();
		for(int j=0;j<len;++j)
			if(tmp[j]==',') tmp[j]='\n';
		tmp[j]='\n';
		stringstream ss(tmp);
		for(int j=0;j<m;++j){
			getline(ss,tmp2);
			if(!fnc.count(tmp2)) fnc[tmp2]=++c;
			dtbs[i][j]=fnc[tmp2];
		}
	}
	for(int i=0;i<m-1;++i){
		for(int j=i+1;j<m;++j){
			map<int,int> fnd;
			for(int k=0;k<n;++k){
				if(fnd.count(dtbs[k][i]*100000+dtbs[k][j])){
					r1=fnd[dtbs[k][i]*100000+dtbs[k][j]]+1;
					r2=k+1; c1=i+1; c2=j+1;
					return true;
				}
				else fnd[dtbs[k][i]*100000+dtbs[k][j]]=k;
			}
		}
	}
	return false;
}
int main(){
	while(cin>>n>>m){
		if(solve()) cout<<"NO\n"<<r1<<' '<<r2<<endl<<c1<<' '<<c2<<endl;
		else cout<<"YES\n";
	}
	return 0;
}