#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
#define MAX 99999999

void dfs(const string &s, set<string> &vis, map<string, map<string, int> > &graph){
	for(auto tup: graph[s]){
		if(!vis.count(tup.first)){
			vis.insert(tup.first);
			dfs(tup.first, vis, graph);
		}
	}
}

int main(){
    int T;
    cin >> T;
    while(T--){
    	map<string, map<string, int> > graph;
    	int n;
    	cin >> n;
    	while(n--){
    		string a, b;
    		cin >> a >> b;
    		int dis;
    		cin >> dis;
    		graph[a][b] = graph[b][a] = dis;
    	}
    	set<string> S;
    	map<string, int> ans;
    	string start, end;
    	cin >> start >> end;
    	set<string> vis;
    	vis.insert(start);
    	dfs(start, vis, graph);
    	if(vis.count(end)){
    		for(auto tup: graph) ans[tup.first] = MAX;
    		ans[start] = 0;
    		while(!S.count(end)){
    			int min = MAX;
    			string a;
    			for(auto tup: ans){
    				if(tup.second < min && !S.count(tup.first)){
    					min = tup.second;
    					a = tup.first;
    				}
    			}
    			S.insert(a);
    			for(auto tup: graph[a])
    				if(!S.count(tup.first) && tup.second + ans[a] < ans[tup.first])
    					ans[tup.first] = tup.second + ans[a];
    		}
    		cout << ans[end] << endl;
    	}
    	else cout << -1 << endl;
    }
    return 0;
}                                 