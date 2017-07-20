#include <iostream>
#include <iomanip>
#include <cstdlib>
int cmp(const void* x, const void *y){
	return *(int*)x-*(int*)y;
}
using namespace std;
int main(){
	int m,n,N,i,v0,v,ans[10000],T=0;
	double p,h;
	while(cin>>m>>n,m){
		if(T) cout<<endl;
		cout<<"Region "<<++T<<endl;
		N=m*n;
		for(i=0;i<N;++i)
			cin>>ans[i];
		cin>>v0;
		qsort(ans,N,sizeof(int),cmp);
		for(i=(v=0)+1;i<N&&v<v0;++i)
			v+=(ans[i]-ans[i-1])*i*100;
		if(i==N&&v<v0){
			p=100;
			h=(double(v0)-v)/(N*100)+ans[N-1];
		}
		else if(!v0){
			p=0;
			h=ans[0];
		}
		else{
			v-=(ans[i-1]-ans[i-2])*(i-1)*100;
			p=(double(i)-1)/N*100;
			h=(double(v0)-v)/((i-1)*100)+ans[i-2];
		}
		cout<<fixed<<setprecision(2)
			<<"Water level is "<<h<<" meters.\n"
			<<p<<" percent of the region is under water.\n";
	}
        cout<<endl;
	return 0;
}
