#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool vis[1005];
int cnt;

void dfs(const vector<int> *graph, vector<int> *comp, int cur){
	comp[cnt].push_back(cur);
	vis[cur] = true;
	for (int neib: graph[cur])
		if(!vis[neib]) dfs(graph, comp, neib);
}

int main(){
	int v, e, t, k = 0;
	while(cin >> v >> e >> t, v){
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		vector<int> graph[v + 5];
		vector<int> comp[v + 5];
		int v1, v2;
		for (int i = 0; i < e; ++i){
			cin >> v1 >> v2;
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
		}
		for (int i = 1; i <= v; ++i){
			if(!vis[i] && !graph[i].empty()){
				dfs(graph, comp, i);
				++cnt;
			}
		}
		int l = e;
		for (int i = 0; i < cnt; ++i){
			int oddPoint = 0;
			for (int ver: comp[i])
				if(graph[ver].size() % 2) ++oddPoint;
			if (!oddPoint) continue;
			l += (oddPoint - 2) / 2;
		}
		l += (cnt? cnt - 1: 0);
		cout << "Case " << ++k << ": " << l * t << endl;
	}
	return 0;
}