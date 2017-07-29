#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

bool graph[220][220], aSign[220][220], hole[220][220], vis[220][220];
int ans[6], cntHole, H, W;
int numOfHole[7] = {0, 5, 0, 3, 2, 4, 1};
char show[6] = {'A', 'D', 'J', 'K', 'S', 'W'};

bool inGraph(int x, int y){
	if(x >= 0 && x < H + 2 && y >= 0 && y < (W + 2) * 4) return true;
	return false;
}

void drawGraph(int x, int y, char c){
	int hex = (isalpha(c)? c - 'a' + 10: c - '0');
	for(int i = 3; i >= 0; --i){
		graph[x][y * 4 + i] = hex % 2;
		hex /= 2;
	}
}

void drawASign(int x, int y){
	aSign[x][y] = true;
	vis[x][y] = true;
	if(inGraph(x + 1, y) && graph[x + 1][y] && !vis[x + 1][y]) drawASign(x + 1, y);
	if(inGraph(x, y + 1) && graph[x][y + 1] && !vis[x][y + 1]) drawASign(x, y + 1);
	if(inGraph(x - 1, y) && graph[x - 1][y] && !vis[x - 1][y]) drawASign(x - 1, y);
	if(inGraph(x, y - 1) && graph[x][y - 1] && !vis[x][y - 1]) drawASign(x, y - 1);
}

void countHole(int x, int y){
	hole[x][y] = true;
	if(inGraph(x + 1, y) && !aSign[x + 1][y] && !hole[x + 1][y]) countHole(x + 1, y);
	if(inGraph(x, y + 1) && !aSign[x][y + 1] && !hole[x][y + 1]) countHole(x, y + 1);
	if(inGraph(x - 1, y) && !aSign[x - 1][y] && !hole[x - 1][y]) countHole(x - 1, y);
	if(inGraph(x, y - 1) && !aSign[x][y - 1] && !hole[x][y - 1]) countHole(x, y - 1);	
}

int main(){
	int kase = 0;
	while(scanf("%d%d", &H, &W), H){
		memset(ans, 0, sizeof(ans));
		memset(graph, 0, sizeof(graph));
		memset(vis, 0, sizeof(graph));
		char c;
		for(int i = 1; i < H + 1; ++i){
			getchar();
			for(int j = 1; j < W + 1; ++j){
				c = getchar();
				drawGraph(i, j, c);
			}
		}
		for(int i = 0; i < H + 2; ++i){
			for(int j = 0; j < (W + 2) * 4; ++j){
				if(graph[i][j] && !vis[i][j]){
					memset(aSign, 0, sizeof(aSign));
					memset(hole, 0, sizeof(hole));
					cntHole = 0;
					drawASign(i, j);
					for(int k = 0; k < H + 2; ++k){
						for(int l = 0; l < (W + 2) * 4; ++l){
							if(!aSign[k][l] && !hole[k][l]){
								++cntHole;
								countHole(k, l);
							}
						}
					}
					++ans[numOfHole[cntHole]];
				}
			}
		}
		printf("Case %d: ", ++kase);
		for(int i = 0; i < 6; ++i)
			for(int j = 0; j < ans[i]; ++j)
				printf("%c", show[i]);
		printf("\n");
	}
	return 0;
}