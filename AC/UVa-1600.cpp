#include <iostream>
#include <cstring>
#include <queue>
#include <iomanip>
#include <cmath>
const int inf = 999999999;
using namespace std;

int dis[25][25][25], grid[25][25];
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};
int m, n, k, t;

struct p{
	p(int _x, int _y): x(_x), y(_y) {}
	int x, y;
};

bool inGraph(int x, int y){
	if(x > 0 && x <= m && y > 0 && y <= n) return true;
	return false;
}

int dfs(int x, int y, int step, int tp){
	if(x == m && y == n) return step;
	int ans = inf;
	for (int i = 0; i < 4; ++i){
		int newX = x + moveX[i], newY = y + moveY[i];
		int pok = tp;
		if(grid[newX][newY]) ++pok;
		else pok = 0;
		if(inGraph(newX, newY) && (dis[newX][newY][pok] < 0 || dis[newX][newY][pok] > step + 1) && pok <= k){
			dis[newX][newY][pok] = step + 1;
			ans = min(ans, dfs(newX, newY, step + 1, pok));
		}
	}
	return ans;
}

int main(){
	cin >> t;
	memset(grid, 0, sizeof(grid));
	while (t--){
		memset(dis, -1, sizeof(dis));
		cin >> m >> n >> k;
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				cin >> grid[i][j];
		int ans = dfs(1, 1, 0, 0);
		ans = ans == inf? -1: ans;
		cout << ans << endl;
	}
	return 0;
}