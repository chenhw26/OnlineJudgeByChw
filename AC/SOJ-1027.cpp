#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
	int N;
	while(cin >> N, N){
		map<string, string> buf, real;
		for(int i = 0; i < N; ++i){
			string id, ip;
			cin >> id >> ip;
			if(buf.count(ip)) real[buf[ip]] = id;
			else buf[ip] = id;
		}
		for(auto i: real)
			cout << i.second << " is the MaJia of " << i.first << endl;
		cout << endl;
	}
	return 0;
}