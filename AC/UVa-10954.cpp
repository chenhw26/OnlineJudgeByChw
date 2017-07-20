#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()

int main(){
	int n;
	while(cin >> n, n){
		list<int> buf;
		int t, sum = 0, x1, x2, x;
		while(n--){
			cin >> t;
			buf.insert(lower_bound(ALL(buf), t), t);
		}
		if(buf.size() == 1) sum = *(buf.begin());
		while(buf.size() > 1){
			list<int>::iterator it = buf.begin();
			x1 = *it;
			it = buf.erase(it);
			x2 = *it;
			it = buf.erase(it);
			x = x1 + x2;
			sum += x;
			buf.insert(lower_bound(ALL(buf), x), x);
		}
		cout << sum << endl;
	}
	return 0;
}