#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int dis[10][10];
int moveX[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int moveY[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

struct p{
	p(int _x, int _y, int _preX, int _preY): x(_x), y(_y), preX(_preX), preY(_preY) {}
	int x, y, preX, preY;
};

bool inGraph(int x, int y){
	if(x > 0 && x < 9 && y > 0 && y < 9) return true;
	return false;
}

int bfs(int startY, int startX, int endY, int endX){
	dis[startX][startY] = 0;
	queue<p> q;
	if(endX == startX && endY == startY) return 0;
	for (int i = 0; i < 8; ++i){
		int newX = startX + moveX[i], newY = startY + moveY[i];
		if(inGraph(newX, newY) && dis[newX][newY] == -1){
			q.push(p(newX, newY, startX, startY));
			dis[newX][newY] = dis[startX][startY] + 1;
		}
	}
	while (1){
		p cur = q.front(); q.pop();
		if(cur.x == endX && cur.y == endY) break;
		for (int i = 0; i < 8; ++i){
			int newX = cur.x + moveX[i], newY = cur.y + moveY[i];
			if(inGraph(newX, newY) && dis[newX][newY] == -1){
				q.push(p(newX, newY, cur.x, cur.y));
				dis[newX][newY] = dis[cur.x][cur.y] + 1;
			}
		}
	}
	return dis[endX][endY];
}

int main(){
	string start, end;
	while (cin >> start){
		memset(dis, -1, sizeof(dis));
		cin >> end;	
		printf("To get from %s to %s takes %d knight moves.\n", start.c_str(), end.c_str(), bfs(start[0] - 'a' + 1, start[1] - '0', end[0] - 'a' + 1, end[1] - '0'));
	}
	return 0;
}