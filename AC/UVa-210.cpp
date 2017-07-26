#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

class statement{
public:
	statement(int t, const string &_var = "", int v = 0): type(t), val(v), var(_var){}
	int type, val;
	string var;
};

class prog{
public:
	int id;
	deque<statement> allStat;
};

map<string, int> allVar;

int main(){
	int n, m, t[6], quantum;
	cin >> m;
	while(m--){
		allVar.clear();
		cin >> n >> t[1] >> t[2] >> t[3] >> t[4] >> t[5] >> quantum;
		prog allProg[n + 1];
		deque<prog> ready;
		queue<prog> blocked;
		string cmd;
		for(int i = 1; i <= n; ++i){
			allProg[i].id = i;
			while(cin >> cmd, cmd != "end"){
				if(cmd == "lock") allProg[i].allStat.push_back(statement(3));
				else if(cmd == "unlock") allProg[i].allStat.push_back(statement(4));
				else if(cmd == "print"){
					string var; cin >> var;
					allProg[i].allStat.push_back(statement(2, var));
				}
				else{
					char gar;
					int val; 
					cin >> gar >> val;
					allProg[i].allStat.push_back(statement(1, cmd, val)); 
				}
			}
			allProg[i].allStat.push_back(statement(5));
			ready.push_back(allProg[i]);
		}
		bool is_lock = false;
		while(!ready.empty()){
			int time = 0;
			bool is_ready = true;
			prog run = ready.front(); ready.pop_front();
			while(time < quantum){
				if(run.allStat.empty()) {is_ready = false; break;}
				statement curStat = run.allStat.front(); run.allStat.pop_front();
				time += t[curStat.type];
				if(curStat.type == 1) allVar[curStat.var] = curStat.val;
				else if(curStat.type == 2) cout << run.id << ": " << allVar[curStat.var] << endl;
				else if(curStat.type == 3){
					if(is_lock){
						is_ready = false;
						run.allStat.push_front(curStat);
						blocked.push(run);
						break;
					}
					else is_lock = true;
				}
				else if(curStat.type == 4){
					if(!blocked.empty()) {ready.push_front(blocked.front()); blocked.pop();}
					is_lock = false;
				}
			}
			if(is_ready) ready.push_back(run);
		}
		if(m) cout << endl;
	}
	return 0;
}