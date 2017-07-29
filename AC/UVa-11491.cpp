#include <iostream>
using namespace std;

int max(int num[], int begin, int last){
	int m = -1, i = begin, mi;
	for(; i < last; ++i){
		if(num[i] > m){
			m = num[i];
			mi = i;
		}
	}
	return mi;
}

int main(){
	int N, D;
	while(cin >> N >> D, N){
		getchar();
		int num[N], b = N - D, first = 0;
		for(int i = 0; i < N; ++i)
			num[i] = getchar() - '0';
		for(int i = 0; i < b; ++i){
			first = max(num, first, N - b + i + 1) + 1;
			cout << num[first - 1];
		}
		cout << endl;
	}
}