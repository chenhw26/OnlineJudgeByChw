#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <sstream>
using namespace std;
int main(){
	string s,t;
	set<string> dic;
	while(cin>>s){
		for(int i=0;i<s.length();++i){
			if(isalpha(s[i]))
				s[i]=tolower(s[i]);
			else
				s[i]=' ';
		}
		stringstream ss(s);
		while(ss>>t)
			dic.insert(t);
	}
	for(set<string>::iterator i=dic.begin();i!=dic.end();++i)
		cout<<*i<<endl;
	return 0;
}