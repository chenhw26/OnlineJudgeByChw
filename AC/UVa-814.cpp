#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

void transAddr(const string &addr, string &mta, string &name){
	size_t a = addr.find('@');
	name = addr.substr(0, a);
	mta = addr.substr(a + 1);
}

int main(){
	string s;
	set<string> addr;
	while(cin >> s, s != "*"){
		string mta, name;
		int n;
		cin >> mta >> n;
		while(n--){
			cin >> name;
			addr.insert(name + "@" + mta);
		}
	}
	while(cin >> s, s != "*"){
		string sendMta, sendName;
		vector<string> tarMta;
		map<string, vector<string> > allName;
		set<string> vit;
		transAddr(s, sendMta, sendName);
		while(cin >> s, s != "*"){
			string revMta, revName;
			transAddr(s, revMta, revName);
			if(!vit.count(s)){
				vit.insert(s);
				if(!allName.count(revMta)) tarMta.push_back(revMta);
				allName[revMta].push_back(revName);
			}
		}
		vector<string> text;
		cin.ignore();
		while(getline(cin, s), s != "*") text.push_back("     " + s);
		for(auto mta: tarMta){
			cout << "Connection between " << sendMta << " and " << mta << endl;
			cout << "     HELO " << sendMta << endl << "     250" << endl;
			cout << "     MAIL FROM:<" << sendName << "@" << sendMta << ">" << endl << "     250" << endl;
			bool send = false;
			for(auto name: allName[mta]){
				cout << "     RCPT TO:<" << name << "@" << mta << ">" << endl;
				if(addr.count(name + "@" + mta)){
					cout << "     250" << endl;
					send = true;
				}
				else cout << "     550" << endl;
			}
			if(send){
				cout << "     DATA" << endl << "     354" << endl;
				for(auto t: text) cout << t << endl;
				cout << "     ." << endl << "     250" << endl;
			}
			cout << "     QUIT" << endl << "     221" << endl;
		}
	}
	return 0;
}