#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
typedef struct tree
{
	int data;
	struct tree* leftson;
	struct tree* rightson;
} Tree;
typedef Tree* Treeptr;
const int maxn=10000;
int inor[maxn],posor[maxn],n,lst,rt;
void input(int value,int left,int right,Treeptr* tptr){
	if(right>left){
		*tptr=new Tree;
		memset(*tptr,0,sizeof(Tree));
		(*tptr)->data=value;
		--n;
		int i;
		for(i=0;inor[i]!=value;++i);
		input(posor[n],i+1,right,&((*tptr)->rightson));
		input(posor[n],left,i,&((*tptr)->leftson));
	}
}
void find(int sum,Treeptr trptr){
	bool is_leaf=true;
	if(trptr->leftson){
		find(sum+trptr->data,trptr->leftson);
		is_leaf=false;
	}
	if(trptr->rightson){
		find(sum+trptr->data,trptr->rightson);
		is_leaf=false;
	}
	if(is_leaf){
		if(sum+trptr->data<lst){
			rt=trptr->data;
			lst=sum+trptr->data;
		}
		else if(sum+trptr->data==lst && trptr->data<rt)
			rt=trptr->data;
	}
}
void freetree(Treeptr frptr){
	if(frptr->leftson)
		freetree(frptr->leftson);
	if(frptr->rightson)
		freetree(frptr->rightson);
	delete frptr;
}
int main(){
	string str_inor,str_posor;
	while(getline(cin,str_inor)){
		getline(cin,str_posor);
		stringstream ss_in(str_inor);
		n=0;
		for(int i=0;ss_in>>inor[i];++i,++n);
		stringstream ss_pos(str_posor);
		for(int i=0;ss_pos>>posor[i];++i);
		n--;
		Treeptr root;
		input(posor[n],0,n+1,&root);
		lst=rt=1000001;
		find(0,root);
		cout<<rt<<endl;
		freetree(root);
	}
	return 0;
}