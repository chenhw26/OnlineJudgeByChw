#include <iostream>
#include <string>
using namespace std;
int main(){
	string ori;
	while(cin>>ori){
		int i,len=ori.length(),crs;
		string ans;
		for(i=0;i<len&&ori[i]!=']'&&ori[i]!='[';++i)
			ans+=ori[i];
		while(i<len){
			if(ori[i]==']') crs=0;
			else if(ori[i]=='[') crs=1;
			string cur;
			for(++i;i<len&&ori[i]!='['&&ori[i]!=']';++i)
				cur+=ori[i];
			if(crs) ans=cur+ans;
			else ans+=cur;
		}
		cout<<ans<<endl;
	}
	return 0;
}