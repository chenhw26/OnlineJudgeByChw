#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct r{
	int y;
	int x[1000];
	int size;
};
bool solve(r *pnt, int cnt){
	for(int i=0;i<cnt;++i){
		if(pnt[i].size%2){
			sort(pnt[i].x,(pnt[i].x)+(pnt[i].size));
			int axis=pnt[i].x[pnt[i].size/2];
			for(int j=0;j<cnt;++j){
				sort(pnt[j].x,(pnt[j].x)+(pnt[j].size));
				if(pnt[j].size%2&&pnt[j].x[pnt[j].size/2]!=axis)
					return false;
				else if(pnt[j].size%2==0&&pnt[j].x[pnt[j].size/2-1]+pnt[j].x[pnt[j].size/2]!=2*axis)
					return false;
			}
			return true;
		}
	}
	sort(pnt[0].x,pnt[0].x+pnt[0].size);
	int axis2=pnt[0].x[pnt[0].size/2]+pnt[0].x[pnt[0].size/2-1];
	for(int i=1;i<cnt;++i){
		sort(pnt[i].x,pnt[i].x+pnt[i].size);
		if(pnt[i].x[pnt[i].size/2]+pnt[i].x[pnt[i].size/2-1]!=axis2)
			return false;
	}
	return true;
}
int main(){
	int t,n,cnt,x0,y0,i;
	cin>>t;
	while(t--){
		cin>>n;
		r *pnt=new r[n];
		memset(pnt,0,sizeof(r)*n);
		cnt=0;
		while(n--){
			cin>>x0>>y0;
			for(i=0;i<cnt;++i)
				if(pnt[i].y==y0) break;
			if(i==cnt){
				pnt[cnt].x[pnt[cnt].size]=x0;
				++pnt[cnt].size;
				pnt[cnt++].y=y0;
			}
			else{
				pnt[i].x[pnt[i].size]=x0;
				++pnt[i].size;
			}
		}
		cout<<(solve(pnt,cnt)?"YES\n":"NO\n");
		delete [] pnt;
	}
	return 0;
}