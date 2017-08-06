#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <deque>
#include <string>
using namespace std;

bool graph[70][70];
set<int> seq;
int moveX[4] = {0, 0, 1, 1};
int moveY[4] = {0, 1, 0, 1};
int n;

void init(){
	seq.clear();
	memset(graph, 0, sizeof(graph));
}

deque<int> tenToFive(int tens){
	deque<int> ans;
	while(tens){
		ans.push_front(tens % 5);
		tens /= 5;
	}
	return ans;
}

int fiveToTen(const deque<int> &fives){
	int ans = 0;
	for (auto i: fives)
		ans = ans * 5 + i;
	return ans;
}

bool allZero(int x, int y, int step){
	for (int i = x; i - x < step; ++i)
		for (int j = y; j - y < step; ++j)
			if(graph[i][j]) return false;
	return true;
}

bool allOne(int x, int y, int step){
	for (int i = x; i - x < step; ++i)
		for (int j = y; j - y < step; ++j)
			if(!graph[i][j]) return false;
	return true;
}

void dfs(int x, int y, const deque<int> &five, int step){
	if(allZero(x, y, step)) return;
	else if(allOne(x, y, step)){
		seq.insert(fiveToTen(five));
		return;
	}
	else{
		for (int i = 0; i < 4; ++i){
			deque<int> d(five);
			d.push_front(i + 1);
			dfs(x + moveX[i] * step / 2, y + moveY[i] * step / 2, d, step / 2);
		}
	}
}

void graphToSeq(){
	string s;
	for (int i = 1; i <= n; ++i){
		cin >> s;
		for (int j = 1; j <= n; ++j)
			graph[i][j] = (s[j - 1] == '1');
	}
	deque<int> five;
	dfs(1, 1, five, n);
	int tmp = 0;
	for (int s: seq){
		cout << s;
		if(tmp == seq.size() - 1) cout << endl;
		else cout << (++tmp % 12? ' ': '\n');
	}
	cout << "Total number of black nodes = " << seq.size() << endl;
}

void draw(int x, int y, int step){
	for (int i = x; i - x < step; ++i)
		for (int j = y; j - y < step; ++j) 
			graph[i][j] = true;
}

void seqToGraph(){
	int tens;
	n *= -1;
	while(cin >> tens, tens != -1){
		deque<int> five(tenToFive(tens));
		int step = n, x = 1, y = 1;
		for (deque<int>::reverse_iterator it = five.rbegin(); it != five.rend(); ++it){
			step /= 2;
			x += moveX[*it - 1] * step;
			y += moveY[*it - 1] * step;
		}
		draw(x, y, step);
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			cout << (graph[i][j]? '*': '.');
		cout << endl;
	}
}

int main(){
	int kase = 0;
	while(cin >> n, n){
		if(++kase != 1) cout << endl;
		init();
		cout << "Image " << kase << endl;
		if(n > 0) graphToSeq();
		else seqToGraph();
	}
	return 0;
}