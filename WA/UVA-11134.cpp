#include <iostream>
#include <algorithm>
using namespace std;
struct Ju{
	int xl,yl,xr,yr;
	int num,x,y;
};
bool xcmp(Ju a, Ju b){
	if(a.xl==b.xl) return a.xr<b.xr;
	return a.xl<b.xl;
}
bool ycmp(Ju a, Ju b){
	if(a.yl==b.yl) return a.yr<b.yr;
	return a.yl<b.yl;
}
bool cmp(Ju a, Ju b){
	return a.num<b.num;
}
int solve(Ju *ju, int n){
	sort(ju,ju+n,xcmp);
	if(ju[0].xl>1) return 0;
	ju[0].x=1;
	for(int i=1;i<n;++i){
		if(ju[i-1].x+1<ju[i].xl||ju[i-1].x+1>ju[i].xr)
			return 0;
		ju[i].x=ju[i-1].x+1;
	}
	sort(ju,ju+n,ycmp);
	if(ju[0].yl>1) return 0;
	ju[0].y=1;
	for(int i=1;i<n;++i){
		if(ju[i-1].y+1<ju[i].yl||ju[i-1].y+1>ju[i].yr)
			return 0;
		ju[i].y=ju[i-1].y+1;
	}
	return 1;
}
int main(){
	Ju ju[5000];
	int n;
	while(cin>>n,n){
		for(int i=0;i<n;++i){
			cin>>ju[i].xl>>ju[i].yl>>ju[i].xr>>ju[i].yr;
			ju[i].num=i;
		}
		if(!solve(ju,n)) cout<<"IMPOSSIBLE\n";
		else{
			sort(ju,ju+n,cmp);
			for(int i=0;i<n;++i)
				cout<<ju[i].x<<' '<<ju[i].y<<endl;
		}
	}
	return 0;
}