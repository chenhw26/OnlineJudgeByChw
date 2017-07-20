#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(){
	string tmp;
	set<string> dict;
	while(cin>>tmp)
		dict.insert(tmp);
	for(set<string>::iterator i=dict.begin();i!=dict.end();++i){
		int len=(*i).length();
		string t1,t2;
		for(int t=0;t<len-1;++t){
			int j;
			for(j=1,t1=(*i)[0];j<=t;++j) t1+=(*i)[j];
			for(t2=(*i)[j++];j<len;++j) t2+=(*i)[j];
			if(dict.count(t1)&&dict.count(t2)){
				cout<<*i<<endl;
				break;
			}
		}
	}
	return 0;
}