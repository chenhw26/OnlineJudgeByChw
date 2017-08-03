#include <iostream>
#include <string>
using namespace std;

void dfs(const string &in, const string &pre){
	if(!in.empty()){
		int index = in.find(pre[0]);
		dfs(in.substr(0, index), pre.substr(1, index));
		dfs(in.substr(index + 1), pre.substr(index + 1));
		cout << pre[0];
	}
}

int main(){
	string in, pre;
	while(cin >> pre){
		cin >> in;
		dfs(in, pre);
		cout << endl;
	}
	return 0;
}