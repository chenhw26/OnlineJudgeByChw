#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

bool vis['z' + 1], connect['z' + 1];

bool solve(int out[], int in[]){
	int start = 0, end = 0;
	for(int i = 'a'; i <= 'z'; ++i){
		if(out[i] - in[i] == 1){
			start = i;
			break;
		}
	}
	for(int i = 'a'; i <= 'z'; ++i){
		if(in[i] - out[i] == 1){
			end = i;
			break;
		}
	}
	for(int i = 'a'; i <= 'z'; ++i){
		if(i == start || i == end) continue;
		if(in[i] != out[i]) return false;
	}
	return true;
}

void dfs(const vector<char> *e, char c){
	vis[c] = true;
	for(char next: e[c])
		if(!vis[next]) dfs(e, next);
}

bool solve2(){
	for(int i = 'a'; i <= 'z'; ++i)
		if(!vis[i] && connect[i]) return false;
	return true;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		memset(vis, 0, sizeof(vis));
		memset(connect, 0, sizeof(connect));
		vector<char> e['z' + 1];
		int m, out['z' + 1] = {0}, in['z' + 1] = {0};
		string s;
		cin >> m;
		while(m--){
			cin >> s;
			connect[s[0]] = true;
			connect[s[s.length() - 1]] = true;
			++out[s[0]];
			++in[s[s.length() - 1]];
			e[s[0]].push_back(s[s.length() - 1]);
			e[s[s.length() - 1]].push_back(s[0]);
		}
		int first;
		for(first = 'a'; !connect[first]; ++first);
		dfs(e, first);
		cout << (solve(out, in) && solve2()? "Ordering is possible.": "The door cannot be opened.") << endl;
	}
	return 0;
}