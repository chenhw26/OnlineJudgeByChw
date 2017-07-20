#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<int> pile[30];
void find(int a, int& p, int& h){
	for(p=0;p<n;++p)
		for(h=0;h<int(pile[p].size());++h)
			if(pile[p][h]==a)
				return;
}
void clear_above(int p, int h){
	for(int i=h+1;i<int(pile[p].size());++i)
		pile[pile[p][i]].push_back(pile[p][i]);
	pile[p].resize(h+1);
}
void pile_onto(int p, int h, int p2){
	for(int i=h;i<int(pile[p].size());++i)
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
}
void show(){
	for(int i=0;i<n;++i){
		cout<<i<<':';
		for(int j=0;j<int(pile[i].size());++j)
			cout<<' '<<pile[i][j];
		cout<<endl;
	}
}
int main(){
	int a,b;
	string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++)
		pile[i].push_back(i);
	while(cin>>s1>>a>>s2>>b){
		int pa,pb,ha,hb;
		find(a,pa,ha);
		find(b,pb,hb);
		if(pa==pb) continue;
		if(s1=="move")
			clear_above(pa,ha);
		if(s2=="onto")
			clear_above(pb,hb);
		pile_onto(pa,ha,pb); 
	}
	show();
	return 0;
}