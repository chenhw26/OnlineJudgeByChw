#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class person{
public:
	int id;
	set<int> unknow;
	bool operator<(const person &rhs){
		return rhs.unknow.size() < unknow.size();
	}
};

bool join(const person &per, const set<int> team){
	for (auto p: per.unknow)
		if(team.count(p)) return false;
	return true;
}

int main(){
	int kase;
	cin >> kase;
	while(kase--){
		person allPerson[105];
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i){
			allPerson[i].id = i;
			int a;
			set<int> tmp;
			while(cin >> a, a) tmp.insert(a);
			for (int j = 1; j <= n; ++j){
				if(j == i) continue;
				else if(!tmp.count(j)){
					allPerson[i].unknow.insert(j);
					allPerson[j].unknow.insert(i);
				}
			}
		}
		sort(allPerson + 1, allPerson + n + 1);
		set<int> team1, team2;
		bool hasSol = true;
		for (int i = 1; i <= n; ++i){
			bool join1 = join(allPerson[i], team1), join2 = join(allPerson[i], team2);
			if (join1 && !join2) team1.insert(allPerson[i].id);
			else if(join2 && !join1) team2.insert(allPerson[i].id);
			else if(!join1 && !join2){
				hasSol = false;
				break;
			} 
			else{
				if(team1.size() > team2.size()) team2.insert(allPerson[i].id);
				else team1.insert(allPerson[i].id);
			}
		}
		if(hasSol){
			cout << team1.size() << ' ';
			for (auto p: team1) cout << p << ' ';
			cout << endl;
			cout << team2.size() << ' ';
			for (auto p: team2) cout << p << ' ';		
		}
		else cout << "No solution";
		cout << endl << endl;
	}
	return 0;
}