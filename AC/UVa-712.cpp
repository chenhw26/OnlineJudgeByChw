#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n, k = 0;
	while(cin >> n, n){
		bool tree[int(pow(2, n + 1)) + 5];
		int seq[n + 5];
		string s;
		for(int i = 1; i <= n; ++i){
			cin >> s;
			seq[i] = stoi(s.substr(1));
		}
		cin >> s;
		int t = pow(2, n + 1);
		for(int i = pow(2, n), j = 0; i < t; ++i, ++j)
			tree[i] = (s[j] == '1');
		cin >> t;
		cout << "S-Tree #" << ++k << ":" << endl;
		while(t--){
			cin >> s;
			int index = 1;
			for(int i = 1; i <= n; ++i){
				index = (s[seq[i] - 1] == '1'? index * 2 + 1: index * 2);
			}
			cout << (tree[index]? 1: 0);
		}
		cout << endl << endl;
	}
	return 0;
}