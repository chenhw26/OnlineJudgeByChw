#include <iostream>
#include <string>
using namespace std;

bool div2(string &p){
	int d = 0, r = 0;
	string ans;
	for(char num: p){
		d = (num - '0' + r * 10) / 2;
		r = (num - '0' + r * 10) % 2;
		ans.append(1, char(d + '0'));
	}
	int i = 0;
	for(; i < ans.size() && ans[i] == '0'; ++i);
	p = ans.substr(i);
	return (r == 0);
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
    	string p;
    	cin >> p;
    	int cnt = 1;
    	for(; div2(p); ++cnt);
    	if(i != 1) cout << endl;
    	cout << "Case " << i << ": " << cnt << endl;
    }
    return 0;
}                                 