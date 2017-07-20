#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	vector<long double> r;
	long double num;
	int i=0;
	while(cin>>num){
		r.push_back(sqrt(num));
		++i;
	}
	for(--i;i>=0;--i)
		printf("%.4Lf\n",r[i]);
	return 0;
}