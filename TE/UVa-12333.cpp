#include <iostream>
#include <vector>
using namespace std;

class bigInt{
public:
	vector<int> num;
	bigInt operator+(const bigInt &rhs){
		bigInt ans;
		int carry = 0;
		int i = 0;
		for(; i < num.size() && i < rhs.num.size(); ++i){
			ans.num.push_back((num[i] + rhs.num[i] + carry) % 10);
			carry = (num[i] + rhs.num[i] + carry) / 10;
		}
		for(; i < num.size(); ++i){
			ans.num.push_back((num[i] + carry) % 10);
			carry = (num[i] + carry) / 10;			
		}
		for(; i < rhs.num.size(); ++i){
			ans.num.push_back((rhs.num[i] + carry) % 10);
			carry = (rhs.num[i] + carry) / 10;
		}
		if(carry) ans.num.push_back(carry);
		return ans;
	}
};

bool cmp(const bigInt &big, const string &num){
	if(num.size() > big.num.size()) return false;
	for(int i = 0, j = big.num.size() - 1; i < num.size(); ++i, --j)
		if(big.num[j] != num[i] - '0') return false;
	return true;
}

void find(const vector<bigInt> &fibon, const string &num){
	for(int i = 0; i < 100000; ++i){
		if(cmp(fibon[i], num)){
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(){
	vector<bigInt> fibon(100000);
	fibon[0].num.push_back(1); fibon[1].num.push_back(1);
	for(int i = 2; i < 100000; ++i)
		fibon[i] = fibon[i - 1] + fibon[i - 2];
	int n;
	string num;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> num;
		cout << "Case #" << i << ':';
		find(fibon, num);
	}
	return 0;
}