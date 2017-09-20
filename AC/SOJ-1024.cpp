#include <iostream>
#include <map>
#include <cstring>
using namespace std;                                                       

int max_path;

void find(map<int, map<int, int> > &graph, bool vis[], int curp, int dis){
    bool is_leaf = true;
    for(auto p: graph[curp]){
        if(!vis[p.first]){
            vis[p.first] = 1;
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
        bool *vis = new bool[N + 1];
        memset(vis, 0, sizeof(bool) * (N + 1));
        vis[K] = 1;
        max_path = 0;
        find(graph, vis, K, 0);
        delete [] vis;
        cout << max_path << endl;
    }
    return 0;
}                                 
