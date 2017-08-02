#include <iostream>
#include <map>
#include <string>
#include <list>
#include <sstream>
using namespace std;

class pro{
public:
	list<string> dpndOn, dpnded;
	int status = 0;
};

map<string, pro> allPro;
list<string> installed;

void depend(stringstream &sss){
	string d, s, v;
	sss >> d;
	if(!allPro.count(d)) allPro[d] = pro();
	getline(sss, s);
	stringstream ss(s);
	while(ss >> v){
		allPro[d].dpndOn.push_back(v);
		if(!allPro.count(v)) allPro[v] = pro();
		allPro[v].dpnded.push_back(d);
	}
}

void install(const string &s){
	for(auto p: allPro[s].dpndOn)
		if(!allPro[p].status) install(p);
	installed.push_back(s);
	allPro[s].status = 2;
	cout << "   Installing " << s << endl;
}

bool isNeeded(const string &s){
	for(auto p: allPro[s].dpnded)
		if(allPro[p].status) return true;
	return false;
}

void rmv(const string &s){
	cout << "   Removing " << s << endl;
	allPro[s].status = 0;
	installed.remove(s);
	for(auto p: allPro[s].dpndOn)
		if(allPro[p].status == 2 && !isNeeded(p)) rmv(p);
}

int main(){
	string cmd, buf;
	while(getline(cin, buf), buf != "END"){
		cout << buf << endl;
		stringstream ss(buf);
		ss >> cmd;
		if(cmd == "DEPEND") depend(ss);
		else if(cmd == "INSTALL"){
			string s;
			ss >> s;
			if(allPro.count(s) && allPro[s].status){
				cout << "   " << s << " is already installed." << endl;
				continue;
			}
			if(allPro.count(s))
				for(auto p: allPro[s].dpndOn)
					if(!allPro[p].status) install(p);
			if(!allPro.count(s)) allPro[s] = pro();
			allPro[s].status = 1;
			installed.push_back(s);
			cout << "   Installing " << s << endl;
		}
		else if(cmd == "REMOVE"){
			string s;
			ss >> s;
			if(!allPro.count(s) || !allPro[s].status) cout << "   " << s << " is not installed." << endl;
			else if(isNeeded(s)) cout << "   " << s << " is still needed." << endl;
			else rmv(s);
		}
		else if(cmd == "LIST")
			for(auto p: installed) cout << "   " << p << endl;
	}
	cout << "END" << endl; 
	return 0;
}