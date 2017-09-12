#include <iostream>
#include <vector>
using namespace std;

class bigint{
public:
	vector<int> num;
	
	bigint() = default;

	bigint(int ini){
		while(ini){
			num.push_back(ini % 10);
			ini /= 10;
		}
	}

	bigint operator+(const bigint &rhs){
		bigint rtmp(rhs), ltmp(*this), ans;
		int newsize = num.size() > rhs.num.size()? num.size(): rhs.num.size();
		rtmp.num.resize(newsize, 0); ltmp.num.resize(newsize, 0);
		int carry = 0;
		for(int i = 0; i < newsize; ++i){
			ans.num.push_back((ltmp.num[i] + rtmp.num[i] + carry) % 10);
			carry = (ltmp.num[i] + rtmp.num[i] + carry) / 10;
		}
		if(carry) ans.num.push_back(carry);
		return ans;
	}

	bigint operator-(const bigint &rhs){
		bigint rtmp(rhs), ltmp(*this), ans;
		int newsize = num.size() > rhs.num.size()? num.size(): rhs.num.size();
		rtmp.num.resize(newsize, 0); ltmp.num.resize(newsize, 0);
		int carry = 0;
		for(int i = 0; i < newsize; ++i){
			if(ltmp.num[i] - carry - rtmp.num[i] >= 0){
				ans.num.push_back(ltmp.num[i] - carry - rtmp.num[i]);
				carry = 0;
			}
			else{
				ans.num.push_back(ltmp.num[i] + 10 - carry - rtmp.num[i]);
				carry = 1;
			}
		}
		int i = ans.num.size() - 1;
		for(; ans.num[i] == 0; --i);
		ans.num.resize(i + 1, 0);
		return ans;		
	}

	void print(){
		for(int i = num.size() - 1; i >= 0; --i)
			cout << num[i];
		cout << endl;
	}
};

int main(){
    int m, d;
    while(cin >> m >> d, m){
    	bigint a[d + 5], k[d + 5];
    	a[1] = k[1] = 1;
    	for(int i = 2; i <= d; ++i){
    		a[i] = i - m > 0? a[i - 1] + a[i - m]: a[i - 1];
    		k[i] = i - m > 0? k[i - 1] + a[i] - a[i - m]: k[i - 1] + a[i];
    	}
    	(a[d] + k[d]).print();
    }
    return 0;
}                                 