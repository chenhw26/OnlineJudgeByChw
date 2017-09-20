#include <iostream>
using namespace std;                                                       

int cal(int weight, int w[], int rate[]){
	int i = 0;
	for(; i < 3 && w[i] < weight; ++i);
	return weight * rate[i];
}
                              
int main(){
    int w[3], rate[4], T = 0;
    while(cin >> w[0]){
		cin >> rate[0] >> w[1] >> rate[1] >> w[2] >> rate[2] >> rate[3];
		cout << "Set number " << (++T) << ":" << endl;
		int weight;
		while(cin >> weight, weight){
			int price = cal(weight, w, rate), bestw = weight;
			for(int i = 0; i < 3; ++i){
				if(w[i] + 1 >= weight && (w[i] + 1) * rate[i + 1] < price){
					price = (w[i] + 1) * rate[i + 1];
					bestw = w[i] + 1;
				}
			}
			cout << "Weight (" << weight << ") has best price $" << price << " (add " << bestw - weight << " pounds)" << endl;
		}
		cout << endl;
	}
    return 0;
}                                 
