#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int dirs['Z'];
int sign['Z'];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int sx, sy, gx, gy;

class state{
public:
	int x, y, dir;
	bool vis = false;
	state *last = NULL;
	vector<int> sign;
};

int main(){
	string maze;
	dirs['N'] = 0; dirs['E'] = 1; dirs['S'] = 2; dirs['W'] = 3;
	sign['L'] = -1; sign['F'] = 0; sign['R'] = 1;
	while(cin >> maze, maze != "END"){
		state all_states[15][15][4];
		int x, y, gdir;
		char sdir;
		cin >> sx >> sy >> sdir >> gx >> gy;
		while(cin >> x, x){
			cin >> y;
			string s;
			while(cin >> s, s != "*")
				for(int i = 1; i < s.length(); ++i)
					all_states[x][y][dirs[s[0]]].sign.push_back(sign[s[i]]);
		}
		all_states[sx][sy][dirs[sdir]].x = sx;
		all_states[sx][sy][dirs[sdir]].y = sy;
		bool found = false;
		int curDir = dirs[sdir];
		int curX = sx + dx[curDir], curY = sy + dy[curDir];
		all_states[curX][curY][curDir].vis = true;
		all_states[curX][curY][curDir].x = curX;
		all_states[curX][curY][curDir].y = curY;
		all_states[curX][curY][curDir].dir = curDir;
		if(curX == gx && curY == gy){
			found = true;
			gdir = curDir;
		}
		queue<state*> q;
		q.push(&all_states[curX][curY][curDir]);
		while(!q.empty() && !found){
			state *curState = q.front(); q.pop();
			for(int turn: curState -> sign){
				curDir = (curState -> dir + turn) % 4;
				curDir = curDir >= 0? curDir: curDir + 4;
				curX = curState -> x + dx[curDir], curY = curState -> y + dy[curDir];
				if(!all_states[curX][curY][curDir].vis){
					all_states[curX][curY][curDir].vis = true;
					all_states[curX][curY][curDir].last = curState;
					all_states[curX][curY][curDir].x = curX;
					all_states[curX][curY][curDir].y = curY;
					all_states[curX][curY][curDir].dir = curDir;
					if(curX == gx && curY == gy){
						found = true;
						gdir = curDir;
					}
					q.push(&all_states[curX][curY][curDir]);
				}
			}	
		}
		cout << maze << endl;
		if(!found) cout << "  No Solution Possible" << endl;
		else{
			stack<state*> ans;
			state *p = &all_states[gx][gy][gdir];
			while(p){
				ans.push(p);
				p = p -> last;
			}
			ans.push(&all_states[sx][sy][dirs[sdir]]);
			while(!ans.empty()){
				cout << ' ';
				for(int i = 0; i < 10 && !ans.empty(); ++i){
					cout << " (" << ans.top() -> x << ',' << ans.top() -> y << ')';
					ans.pop();
				}
				cout << endl;
			}
		}
	}
	return 0;
}