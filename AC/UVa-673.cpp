#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solve(const string &s){
	if(s.length() == 0) return true;
	if(s.length() % 2) return false;
	stack<char> st;
	for(char c: s){
		if(c == '[' || c == '(') st.push(c);
		else if(c == ')' || c == ']'){
			if(st.empty()) return false;
			if(c == ')' && st.top() != '(') return false;
			if(c == ']' && st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty();
}

int main(){
	int n;
	cin >> n; cin.ignore();
	while(n--){
		string s;
		getline(cin, s);
		cout << (solve(s)? "Yes": "No") << endl;
	}
	return 0;
}