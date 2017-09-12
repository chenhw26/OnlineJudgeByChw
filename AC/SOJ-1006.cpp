#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dis(const array<int, 5> &a, const array<int, 5> &b){
	int ans = 0;
	for(int i = 0; i < 4; ++i){
		for(int j = i + 1; j < 5; ++j){
			if((a[i] > a[j] && b[i] > b[j]) || (a[i] < a[j] && b[i] < b[j])) ans += 0;
			else ans += 1;
		}
	}
	return ans;
}

int main(){
    int n;
    while(cin >> n, n){
    	string rank;
    	vector<array<int, 5> > all_ranks(n);
    	for(int i = 0; i < n; ++i){
        	cin >> rank;
			for(int j = 0; j < 5; ++j)
				all_ranks[i][rank[j] - 'A'] = j;		
    	}
    	array<array<int, 5>, 120> buf;
    	array<int, 120> med;
    	array<int, 5> tmp = {0, 1, 2, 3, 4};
    	for(int i = 0; i < 120; ++i){
    		int distance = 0;
    		buf[i] = tmp;
    		for(int j = 0; j < n; ++j) distance += dis(tmp, all_ranks[j]);
    		med[i] = distance;
    		next_permutation(tmp.begin(), tmp.end());
    	}
    	array<int, 5> min;
    	int minmed = 99999999;
    	for(int i = 0; i < 120; ++i){
    		if(med[i] < minmed){
    			minmed = med[i];
    			min = buf[i];
    		}
    	}
    	array<char, 5> ans;
    	for(int i = 0; i < 5; ++i)
    		ans[min[i]] = i + 'A';
    	for(char c: ans) cout << c;
    	cout << " is the median ranking with value " << minmed << "." << endl;
    }
    return 0;
}                                 