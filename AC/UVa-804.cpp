#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int NP[105], NT[105][105];
int n, t;

bool enable(int j){
	for (int i = 1; i <= n; ++i)
		if(NP[i] + NT[j][i] < 0) return false;
	return true;
}

void trans(int j){
	for (int i = 1; i <= n; ++i)
		NP[i] += NT[j][i];
}

int main(){
	int kase = 0;
	while(cin >> n, n){
		memset(NT, 0, sizeof(NT));
		for (int i = 1; i <= n; ++i)
			cin >> NP[i];
		cin >> t;
		for (int i = 1; i <= t; ++i){
			int a;
			while(cin >> a, a)
				NT[i][abs(a)] += (a > 0? 1: -1);
		}
		int tol, i = 0;
		cin >> tol;
		bool alive = true;
		for (; i < tol; ++i){
			int j = 1;
			for (; j <= t && !enable(j); ++j);
			if(j == t + 1){
				alive = false;
				break;
			}
			trans(j);
		}
		printf("Case %d: %s after %d transitions\n", ++kase, (alive? "still live": "dead"), i);
		printf("Places with tokens:");
		for (int i = 1; i <= n; ++i)
			if(NP[i]) printf(" %d (%d)", i, NP[i]);
		printf("\n\n");
	}
	return 0;
}