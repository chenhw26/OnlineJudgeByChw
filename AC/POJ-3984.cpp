#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int offsetx[4] = {0, 1, 0, -1};      // x坐标偏移量
int offsety[4] = {1, 0, -1, 0};      // y坐标偏移量
bool vis[5][5], board[5][5];          // vis记录每个格是否访问过，board为迷宫
int Min = 999999999;
vector<pair<int, int> > shortest, cur;

// 判断r行c列是否越界
bool inboard(int r, int c){
    if(r < 0 || r >= 5) return false;
    if(c < 0 || c >= 5) return false;
    return true;
}

void dfs(int x, int y, int length){
    vis[x][y] = true;
    cur.push_back(pair<int, int>(x, y));
    if(length + 4 - x + 4 - y >= Min)
        return;
    if(x == 4 && y == 4){
        if(length < Min){
            Min = length;
            shortest = cur;
        }
    }
    else{
        for(int i = 0; i < 4; ++i){
            int nextx = x + offsetx[i], nexty = y + offsety[i];
            if(inboard(nextx, nexty) && !board[nextx][nexty] && !vis[nextx][nexty]){
                dfs(nextx, nexty, length + 1);
                vis[nextx][nexty] = false;
                cur.pop_back();
            }
        }
    }
}

int main(){
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            cin >> board[i][j];    // 输入迷宫
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            vis[i][j] = false;     // 所有格在开始时都每访问过
    vector<pair<int, int> > output;
    dfs(0, 0, 1);
    for(int i = 0; i < shortest.size(); ++i)
        cout << '(' << shortest[i].first << ", " << shortest[i].second << ')' << endl;
    return 0;
}
