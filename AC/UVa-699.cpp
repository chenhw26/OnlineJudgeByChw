#include <iostream>
#include <map>
using namespace std;

void solve(map<int, int> &sum, int p){
	int v; 
	cin >> v;
	if(v == -1) return;
	if(!sum.count(p)) sum[p] = 0;
	sum[p] += v;
	solve(sum, p - 1);
	solve(sum, p + 1);
}

int main(){
	map<int, int> sum;
	int p = 0, kase = 0;
	while(solve(sum, p), !sum.empty()){
		cout << "Case " << ++kase << ":" << endl;
		map<int, int>::iterator iter = sum.begin();
		cout << iter -> second; ++iter;
		for(; iter != sum.end(); ++iter) cout << ' ' << iter -> second;
		cout << endl << endl;
		sum.clear();
	}
	return 0;
}