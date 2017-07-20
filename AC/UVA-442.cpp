#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int N,mtr['Z'+1][2];
bool solve(string exp, int & ans){
	int len=exp.length();
	stack< vector<int> > s;
	for(int i=0;i<len;++i){
		if(isalpha(exp[i])){
			vector<int> tmp(2);
			tmp[0]=(*(mtr+int(exp[i])))[0];
			tmp[1]=(*(mtr+int(exp[i])))[1];
			s.push(tmp);
		}
		else if(exp[i]==')'){
			int t,hold0,hold1;
			t=(s.top())[0]*(s.top())[1];
			hold0=(s.top())[0];
			hold1=(s.top())[1];
			s.pop();
			if(hold0!=(s.top())[1]) return false;
			ans+=t*s.top()[0];
			hold0=s.top()[0];
			s.pop();
			vector<int> tmp(2);
			tmp[0]=hold0;
			tmp[1]=hold1;
			s.push(tmp);
		}
	}
	return true;
}
int main(){
	char matrix;
	string exp;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>matrix;
		cin>>(*(mtr+int(matrix)))[0]>>(*(mtr+int(matrix)))[1];
	}
	while(cin>>exp){
		int ans=0;
		if(solve(exp,ans)) cout<<ans<<endl;
		else cout<<"error\n";
	}
	return 0;
}