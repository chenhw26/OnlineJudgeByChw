#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;
string stdz(string s){
	for(int i=0;i<s.size();++i)
		s[i]=tolower(s[i]);
	sort(s.begin(), s.end());
	return s;
}
int main(){
	string s,r;
	vector<string> words,ans;
	map<string,int> t;
	while(cin>>s){
		if(s[0]=='#')
			break;
	words.push_back(s);
	r=stdz(s);
	if(!t.count(r))
		t[r]=0;
	++t[r];
	}
	for(int i=0;i<words.size();++i)
		if(t[stdz(words[i])]==1)
			ans.push_back(words[i]);
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();++i)
		cout<<ans[i]<<endl;
	return 0;
}