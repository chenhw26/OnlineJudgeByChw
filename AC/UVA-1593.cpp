#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	string wrz[1000][100],tmp,t;
	int len[100]={0},r[1000],i=0,j;
	while(getline(cin,tmp)){
		stringstream ss(tmp);
		j=0;
		while(ss>>t){
			if(t.length()>len[j])
				len[j]=t.length();
			wrz[i][j++]=t;
		}
		r[i++]=j;
	}
	for(int k=0;k<i;++k){
		for(j=0;j<r[k];++j){
			cout<<wrz[k][j];
			if(j!=r[k]-1)
				for(int l=wrz[k][j].length();l<len[j]+1;++l)
					cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}