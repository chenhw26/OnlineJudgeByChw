#include <iostream>
#include <set>
using namespace std;

int find(int a, int n, int *arr, int begin = 1){
	for(int i = begin; i <= n; ++i)
		if(arr[i] == a) return i;
	return 0;
}

int main(){
	int n;
	while(cin >> n){
		int bfs[n + 5] = {0}, dfs[n + 5] = {0};
		set<int> ans[n + 5];
		bool findAns[n + 5] = {0};
		for (int i = 1; i <= n; ++i) cin >> bfs[i];
		for (int i = 1; i <= n; ++i) cin >> dfs[i];
		for (int i = 1; i <= n; ++i){
			int indexInDFS = find(bfs[i], n, dfs);
			int firstSon = dfs[indexInDFS + 1];
			int firstSonIndexInBFS = find(firstSon, n, bfs, i + 1);
			if(firstSonIndexInBFS){
				int subling = bfs[i + 1];
				int sublingSon = dfs[find(subling, n, dfs) + 1];
				int sublingSonIndexInBFS = find(sublingSon, n, bfs, i + 2);
				int endIndex = sublingSonIndexInBFS && !findAns[sublingSon]? sublingSonIndexInBFS: n + 1;
				for (int j = firstSonIndexInBFS; j < endIndex; ++j){
					if(!findAns[bfs[j]]){
						ans[bfs[i]].insert(bfs[j]);
						findAns[bfs[j]] = true;
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i){
			cout << i << ':';
			for (auto son: ans[i])
				cout << ' ' << son;
			cout << endl;
		}
	}
	return 0;
}