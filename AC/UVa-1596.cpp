#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <cctype>
using namespace std;

class Arr{
public:
	Arr(){};
	void alloc(int n){
		size = n;
		dfn = true;
	}
	map<int, int> p;
	bool dfn = false;
	int size = 0;
};

bool compile(Arr *all_arr, const string &exp, int &res){
	stack<char> buf;
	int j = 0;
	for(; !isdigit(exp[j]); j += 2)
		buf.push(exp[j]);
	res = stoi(exp.substr(j, exp.find(']') - j));
	char arr;
	while(!buf.empty()){
		arr = buf.top(); buf.pop();
		if(!all_arr[arr].dfn) return false;
		if(res >= all_arr[arr].size) return false;
		if(!all_arr[arr].p.count(res)) return false;
		res = all_arr[arr].p[res];
	}
	return true;
}

int bug_hunt(Arr *all_arr, string *code, int len){
	for(int i = 0; i < len; ++i){
		if(code[i].find('=') == string::npos){
			int n;
			if(!compile(all_arr, code[i].substr(2, code[i].size() - 3), n)) return i + 1;
			all_arr[int(code[i][0])].alloc(n);
		}
		else{
			string lhs_exp = code[i].substr(0, code[i].find('='));
			string rhs_exp = code[i].substr(code[i].find('=') + 1);
			int rhs, index;
			if(!compile(all_arr, rhs_exp, rhs)) return i + 1;
			if(!compile(all_arr, lhs_exp.substr(2, lhs_exp.size() - 3), index)) return i + 1;
			char arr = lhs_exp[0];
			if(!all_arr[arr].dfn) return i + 1;
			if(index >= all_arr[arr].size) return i + 1;
			all_arr[arr].p[index] = rhs;
		}
	}
	return 0;
}

int main(){
	string l;
	getline(cin, l);
	while(l != "."){
		string code[1000] = {l};
		int i = 1;
		for(; getline(cin, l), l != "."; ++i)
			code[i] = l;
		Arr all_arr['z' + 1];
		cout << bug_hunt(all_arr, code, i) << endl;
		getline(cin, l);
	}
	return 0;
}