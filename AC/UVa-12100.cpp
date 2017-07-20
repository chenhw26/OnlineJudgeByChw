#include <iostream>
#include <queue>
using namespace std;

class Task{
public:
	Task() = default;
	Task(int _prty, bool _is_mine):prty(_prty), is_mine(_is_mine) {}
	int prty;
	bool is_mine;
};

int max_prty(int *all){
	for(int i = 9; i >= 0; --i)
		if(all[i] != 0) return i;
	return 0;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n, m, all[10] = {0}, p, t = 0;
		queue<Task> q;
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			cin >> p;
			q.push(Task(p, i == m? true: false));
			++all[p];
		}
		Task to_print;
		bool cmplt = false;
		do{
			to_print = q.front(); q.pop();
			if(to_print.prty < max_prty(all))
				q.push(to_print);
			else{
				--all[to_print.prty];
				++t;
				if(to_print.is_mine) cmplt = true;
			}
		}while(!cmplt);
		cout << t << endl;
	}
	return 0;
}