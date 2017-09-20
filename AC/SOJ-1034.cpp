#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

int depth;
bool is_tree;

bool dfs(set<int> forest[], bool vis[], int k[], int cur, int d){
    ++k[d];
    if(d > depth) depth = d;
    for(auto child: forest[cur]){
        if(vis[child]) is_tree = false;
        else{
            vis[child] = true;
            dfs(forest, vis, k, child, d + 1);
        }
    }
}

bool allvis(bool vis[], int n){
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) return false;
	return true;
}

int main(){
    int n, m, x, y;
    while(cin >> n >> m, n){
        int k[n + 1];
        memset(k, 0, sizeof(int) * (n + 1));
        bool vis[n + 1];
        memset(vis, 0, sizeof(bool) * (n + 1));
        set<int> forest[n + 1], rfor[n + 1];
        for(int i = 0; i < m; ++i){
            cin >> x >> y;
            forest[x].insert(y);
            rfor[y].insert(x);
        }
        depth = 0;
        is_tree = true;
        for(int i = 1; i <= n; ++i){
            if(!is_tree) break;
            if(rfor[i].empty()){
                vis[i] = true;
                dfs(forest, vis, k, i, 0);
            }
        }
        is_tree = allvis(vis, n) && is_tree;
		if(is_tree)
            cout << depth << " " << *max_element(k, k + n + 1) << endl;
        else
            cout << "INVALID" << endl;
    }
    return 0;
}                                 
