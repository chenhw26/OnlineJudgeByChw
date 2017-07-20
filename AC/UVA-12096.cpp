#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;
int cur_amnt = 0;

int get_id(Set x){
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	IDcache[x] = cur_amnt;
	return cur_amnt++;
}

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x, x.begin())

int main(){
	int n, m;
	stack<int> s;
	cin >> n;
	while(n--){
		cin >> m;
		string cmd;
		while(m--){
			cin >> cmd;
			if(cmd == "PUSH") s.push(get_id(Set()));
			else if(cmd == "DUP") s.push(s.top());
			else{
				Set lhs(Setcache[s.top()]); s.pop();
				Set rhs(Setcache[s.top()]); s.pop();
				Set ans;
				if(cmd == "INTERSECT") set_intersection(ALL(lhs), ALL(rhs), INS(ans));
				else if(cmd == "UNION") set_union(ALL(lhs), ALL(rhs), INS(ans));
				else if(cmd == "ADD"){ans = rhs; ans.insert(IDcache[lhs]);}
				s.push(get_id(ans));
			}
			cout << Setcache[s.top()].size() << endl;
		}
		cout << "***\n";
	}
	return 0;
} 