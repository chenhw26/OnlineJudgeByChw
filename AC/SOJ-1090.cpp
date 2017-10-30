#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int main(){
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		int graph[n][n];
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				cin >> graph[i][j];
		set<int> con;
		bool iscon[n];
		memset(iscon, 0, sizeof(iscon));
		iscon[0] = true;
		con.insert(0);
		int maxlen = 0;
		for(int i = 0; i < n - 1; ++i){
			int nearest, minlen = 65537;
			for(int j: con){
				for(int k = 0; k < n; ++k){
					if(!iscon[k] && graph[j][k] < minlen){
						nearest = k;
						minlen = graph[j][k];
					}
				}
			}
			con.insert(nearest);
			iscon[nearest] = true;
			if(minlen > maxlen)
				maxlen = minlen;
		}
		cout << maxlen << endl;
		if(T) cout << endl;
	}
} 
