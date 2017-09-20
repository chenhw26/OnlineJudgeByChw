#include <iostream>
#include <map>
#include <set>
using namespace std;                                                       

int max_path;

void find(map<int, map<int, int> > &graph, set<int> &vis, int curp, int dis){
	bool is_leaf = true;
	for(auto p: graph[curp]){
		if(!vis.count(p.first)){
			vis.insert(p.first);
			is_leaf = false;
			find(graph, vis, p.first, dis + graph[curp][p.first]);
		}
	}
	if(is_leaf)
		if(dis > max_path)
			max_path = dis;
}
                                       
int main(){
    int N, K, X, Y, D;
    while(cin >> N >> K){
		map<int, map<int, int> > graph;
		for(int i = 0; i < N - 1; ++i){
			cin >> X >> Y >> D;
			graph[X][Y] = graph[Y][X] = D;
		}
		set<int> vis;
		vis.insert(K);
		max_path = 0;
		find(graph, vis, K, 0);
		cout << max_path << endl;
	}
    return 0;
}                                 
