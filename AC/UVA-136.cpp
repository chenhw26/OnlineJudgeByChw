#include <iostream>
#include <set>
using namespace std;
int main(){
	set<long long> ugnm;
	int t[3]={2,3,5},cnt=0;
	ugnm.insert(1);
	for(set<long long>::iterator it=ugnm.begin();cnt<1500;++it,++cnt){
		for(int i=0;i<3&&cnt<1500;++i){
			long long tmp=*it*t[i];
			if(!ugnm.count(tmp))
				ugnm.insert(tmp);
		}
	}
	set<long long>::iterator i;
	int j=0;
	for(i=ugnm.begin();j<1500;++i,++j);
	cout<<"The 1500'th ugly number is "<<*(--i)<<".\n";
	return 0;
}