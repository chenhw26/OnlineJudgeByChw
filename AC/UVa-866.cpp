#include <iostream>
#include <set>
#include <list>
using namespace std;

class pre{
public:
	pre(int f, int l): first(f), last(l){}
	int first, last;
};

bool ismin(const list<pre> &graph, int t){
	for(const pre &re: graph)
		if(re.last == t) return false;
	return true;
}

int main(){
	int n, m;
	while(cin >> n >> m, n){
		set<int> unsorted;
		list<pre> graph;
		list<int> ans;
		for(int i = 1; i <= n; ++i) unsorted.insert(i);
		for(int i = 0; i < m; ++i){
			int f, l;
			cin >> f >> l;
			graph.push_back(pre(f, l));
		}
		while(!unsorted.empty()){
			int t;
			for(int task: unsorted){
				if(ismin(graph, task)){
					t = task;
					break;
				}
			}
			ans.push_back(t);
			graph.remove_if([t](const pre &p){return p.first == t;});
			unsorted.erase(t);
		}
		int i = 0;
		for(int t: ans){
			cout << t << (i == n - 1? '\n': ' ');
			++i;
		}
	}
	return 0;
}