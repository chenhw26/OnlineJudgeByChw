#include <iostream>
#include <string>
#include <map>
using namespace std;

int cnt;
map<__int128, int> buf;
string mob;

void dfs(int d, int begin, int end){
	if(mob[begin] == '['){
		int c = 0;
		for (int i = begin + 1; i < end; ++i){
			if(mob[i] == '[') ++c;
			else if(mob[i] == ']') --c;
			if(c == 0 && mob[i] == ','){
				dfs(d + 1, begin + 1, i);
				dfs(d + 1, i + 1, end - 1);
				break;
			}
		}
	}
	else{
		__int128 w = __int128(stoll(mob.substr(begin, end - begin)));
		__int128 sumw = w << d;
		if(!buf.count(sumw)) buf[sumw] = 0;
		++buf[sumw];
		++cnt;
	}
}

int main(){
	int n;
	cin >> n;
	while (n--){
		cin >> mob;
		cnt = 0; buf.clear();
		dfs(0, 0, mob.size());
		int max = 0;
		for (auto dou: buf)
			if(dou.second > max) max = dou.second;
		cout << cnt - max << endl;
	}
	return 0;
}