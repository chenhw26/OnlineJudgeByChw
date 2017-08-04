#include <iostream>
using namespace std;
int main(){
	int D,I,l;
	cin>>l;
	while(cin>>D,D!=-1){
		cin>>I;
		int p=1;
		for(int i=0;i<D-1;++i){
			if(I%2) {p*=2;I=I/2+1;}
			else {p=p*2+1;I/=2;}
		}
		cout<<p<<endl;
	}
	return 0;
}