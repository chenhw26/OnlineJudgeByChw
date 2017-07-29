#include <cstdio>
#include <cstring>
using namespace std;

int cnt, m, n;
char grid[105][105];
bool sig[105][105];

bool inGrid(int x, int y){
	if(x >= 0 && x < m && y >= 0 && y < n) return true;
	return false;
}

void dfs(int x, int y){
	sig[x][y] = true;
	for(int i = -1; i < 2; ++i)
		for(int j = -1; j < 2; ++j)
			if(inGrid(x + i, y + j) && grid[x + i][y + j] == '@' && !sig[x + i][y + j])
				dfs(x + i, y + j);
}

int main(){
	while(scanf("%d%d", &m, &n), m){
		cnt = 0;
		memset(sig, 0, sizeof(sig));
		for(int i = 0; i < m; ++i)
			scanf("%s", grid[i]);
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(grid[i][j] == '@' && !sig[i][j]){
					++cnt;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}