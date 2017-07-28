#include <iostream>
#include <string>
using namespace std;

void draw(bool *g, int x, int d){
	char color;
	cin >> color;
	if(color == 'f')
		for(int i = x; i - x < 1024 / d; ++i)
			g[i] = true;
	else if(color == 'p'){
		draw(g, x, d * 4);
		draw(g, x + 1024 / d / 4, d * 4);
		draw(g, x + 1024 / d / 4 * 2, d * 4);
		draw(g, x + 1024 / d / 4 * 3, d * 4);
	}
}

int count(bool *g1, bool *g2){
	int cnt = 0;
	for(int i = 0; i < 1024; ++i)
		if(g1[i] || g2[i]) ++cnt;
	return cnt;
}

int main(){
	int n;
	cin >> n;
	while(n--){
		bool first[1024] = {0}, second[1024] = {0};
		draw(first, 0, 1);
		draw(second, 0, 1);
		cout << "There are " << count(first, second) << " black pixels." << endl;
	}
	return 0;
}