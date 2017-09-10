#include <iostream>
#include <string>
using namespace std;

int bigmod(const string &big, int mod){
	int ans = 0;
	for(char c: big) ans = (ans * 10) % mod + (int(c) - '0') % mod;
	return ans % mod;
}

int main(){
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		int mod[n];
		string big;
		for(int i = 0; i < n; ++i) cin >> mod[i];
		cin >> big;
		cout << '(' << bigmod(big, mod[0]);
		for(int i = 1; i < n; ++i) cout << ',' << bigmod(big, mod[i]);
		cout << ')' << endl;
	}
	return 0;
}