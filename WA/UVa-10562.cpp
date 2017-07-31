#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isNode(const char &c){
	if(c == '#' || c == ' ' || c == '|' || c == '-' || !c || c == '\n') return false;
	return true;
}

void print(const vector<string> &tree, int x, int y){
	cout << tree[x][y] << '(';
	if(x + 3 < tree.size() && tree[x + 1][y] == '|'){
		int begin = y, end = y;
		for(; begin >= 0 && tree[x + 2][begin] == '-'; --begin);
		for(; end < tree[x + 2].size() && tree[x + 2][end] == '-'; ++end);
		for(int i = begin + 1; i < end; ++i)
			if(isNode(tree[x + 3][i])) print(tree, x + 3, i);
	}
	cout << ')';
}

int main(){
	int T;
	cin >> T; cin.ignore();
	while(T--){
		vector<string> tree;
		string s;
		while(getline(cin, s), s[0] != '#') tree.push_back(s);
		if(tree.empty()) cout << "()";
		else{
			cout << '(';
			for(int i = 0; i < tree[0].size(); ++i)
				if(isNode(tree[0][i])) print(tree, 0, i);
			cout << ')';
		}
		cout << endl;
	}
	return 0;
}