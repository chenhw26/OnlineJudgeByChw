#include <iostream>
#include <iomanip>
using namespace std;
struct Room{
	int J,F;
	double JF;
};
int main(){
	int M,N,sumF,i;
	double sumJ;
	Room r[1001];
	while(cin>>M>>N,~M){
		for(i=0;i<N;++i){
			cin>>r[i].J>>r[i].F;
			r[i].JF=double(r[i].J)/r[i].F;
		}
		for(i=1;i<N;++i){
			for(int j=i;j&&r[j].JF>r[j-1].JF;--j){
				Room t=r[j];
				r[j]=r[j-1];
				r[j-1]=t;
			}
		}
		for(i=sumJ=sumF=0;i<N&&sumF<M;++i){
			sumF+=r[i].F;
			sumJ+=r[i].J;
		}
		if((!(i==N&&sumF<=M))&&M){
			sumF-=r[i-1].F;
			sumJ-=r[i-1].J;
			sumJ+=r[i-1].J*(double(M-sumF)/r[i-1].F);
		}
		cout<<fixed<<setprecision(3)<<sumJ<<endl;
	}
	return 0;
}